#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, p[MAX];
    int dp[MAX][MAX];
    int split[MAX][MAX];
    int i, j, k, len;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX)
        return 0;

    printf("Enter %d dimensions: ", n + 1);

    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (i = 1; i <= n; i++)
        dp[i][i] = 0;

    for (len = 2; len <= n; len++) {
        for (i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                long long cost = (long long)dp[i][k]
                    + dp[k + 1][j]
                    + (long long)p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = (int)cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("Minimum scalar multiplications = %d\n",
           dp[1][n]);

    printf("Optimal split positions:\n");

    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++)
            printf("%d ", i == j ? 0 : split[i][j]);
        printf("\n");
    }

    return 0;
}