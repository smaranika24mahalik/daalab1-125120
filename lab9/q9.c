
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main()
{
    int n, i, j, k, len;

    int w[MAX], prefix[MAX];

    int dp[MAX][MAX];

    printf("Enter number of weights: ");
    scanf("%d", &n);

    printf("Enter weights:\n");

    prefix[0] = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        prefix[i+1] = prefix[i] + w[i];
        dp[i][i] = 0;
    }

    // Calculate optimal cost
    for(len = 2; len <= n; len++)
    {
        for(i = 0; i <= n-len; i++)
        {
            j = i + len - 1;

            dp[i][j] = INT_MAX;

            int sum = prefix[j+1] - prefix[i];

            for(k = i; k < j; k++)
            {
                int cost = dp[i][k] +
                           dp[k+1][j] + sum;

                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum optimal alphabetic tree cost = %d\n",
           dp[0][n-1]);

    return 0;
}
