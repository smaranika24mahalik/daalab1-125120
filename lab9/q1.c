
#include <stdio.h>

int main()
{
    int n, i, j, t;
    float W, remaining, totalValue = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float v[n], w[n], lambda[n];
    int selected[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter value, weight and decay rate: ");
        scanf("%f %f %f", &v[i], &w[i], &lambda[i]);
        selected[i] = 0;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &W);

    remaining = W;
    t = 0;

    while(remaining > 0)
    {
        int best = -1;
        float maxDensity = 0;

        // Find item with highest current density
        for(i = 0; i < n; i++)
        {
            if(selected[i] == 0)
            {
                float density = (v[i] / w[i])
                                - lambda[i] * t;

                if(density > maxDensity)
                {
                    maxDensity = density;
                    best = i;
                }
            }
        }

        // No positive-density item available
        if(best == -1)
            break;

        // Select full or fractional item
        float fraction;

        if(w[best] <= remaining)
            fraction = 1.0;
        else
            fraction = remaining / w[best];

        totalValue += fraction * w[best] * maxDensity;

        remaining -= fraction * w[best];

        printf("\nItem %d selected", best + 1);
        printf("\nFraction selected: %.2f", fraction);

        selected[best] = 1;
        t++;
    }

    printf("\n\nTotal value = %.2f", totalValue);
    printf("\nRemaining capacity = %.2f\n", remaining);

    return 0;
}
