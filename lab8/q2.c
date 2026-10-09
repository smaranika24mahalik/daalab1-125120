
#include <stdio.h>

int main() {
    int n, V;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int c[n];
    printf("Enter denominations: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    printf("Enter target amount: ");
    scanf("%d", &V);

    long long dp[V + 1];
    for (int i = 0; i <= V; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= V; j++)
            dp[j] += dp[j - c[i]];
    }

    printf("Total ways = %lld\n", dp[V]);
    return 0;
}
