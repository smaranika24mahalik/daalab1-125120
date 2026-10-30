
#include <stdio.h>

int main()
{
    int n, i, j, stops = 0;

    float D, F;

    printf("Enter target distance: ");
    scanf("%f", &D);

    printf("Enter initial fuel: ");
    scanf("%f", &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    float d[n], fuel[n], heap[n+1];

    for(i = 0; i < n; i++)
    {
        printf("Enter distance and fuel: ");
        scanf("%f %f", &d[i], &fuel[i]);
    }

    // Sort stations by distance
    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(d[i] > d[j])
            {
                float t = d[i];
                d[i] = d[j];
                d[j] = t;

                t = fuel[i];
                fuel[i] = fuel[j];
                fuel[j] = t;
            }

    int size = 0;
    float previous = 0;

    for(i = 0; i <= n; i++)
    {
        float current = (i == n) ? D : d[i];

        F -= current - previous;

        while(F < 0 && size > 0)
        {
            F += heap[1];
            heap[1] = heap[size--];

            int k = 1;

            while(2*k <= size)
            {
                int c = 2*k;

                if(c+1 <= size && heap[c+1] > heap[c])
                    c++;

                if(heap[k] >= heap[c])
                    break;

                float t = heap[k];
                heap[k] = heap[c];
                heap[c] = t;

                k = c;
            }

            stops++;
        }

        if(F < 0)
        {
            printf("Target cannot be reached\n");
            return 0;
        }

        if(i < n)
        {
            heap[++size] = fuel[i];

            int k = size;

            while(k > 1 && heap[k] > heap[k/2])
            {
                float t = heap[k];
                heap[k] = heap[k/2];
                heap[k/2] = t;
                k /= 2;
            }
        }

        previous = current;
    }

    printf("Minimum refuelling stops = %d\n", stops);

    return 0;
}
