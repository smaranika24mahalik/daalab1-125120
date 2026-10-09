
#include <stdio.h>

int main() {
    int n;
    printf("Enter rod length: ");
    scanf("%d", &n);

    int p[n + 1], dp[n + 1], first[n + 1];

    printf("Enter prices for lengths 1 to %d: ", n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = -1;

        for (int j = 1; j <= i; j++) {
            if (p[j] + dp[i - j] > dp[i]) {
                dp[i] = p[j] + dp[i - j];
                first[i] = j;
            }
        }
    }

    printf("Maximum revenue = %d\n", dp[n]);
    printf("Piece lengths: ");

    while (n > 0) {
        printf("%d ", first[n]);
        n -= first[n];
    }

    printf("\n");
    return 0;
}
