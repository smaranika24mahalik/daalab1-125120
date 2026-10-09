#include <stdio.h>

int main() {
    int E, F, i, j;
    int dp[101][1001];

    printf("Enter number of eggs and floors: ");
    scanf("%d %d", &E, &F);

    for (i = 1; i <= E; i++) {
        dp[i][0] = 0;
        if (F >= 1)
            dp[i][1] = 1;
    }

    for (j = 0; j <= F; j++)
        dp[1][j] = j;

    for (i = 2; i <= E; i++) {
        for (j = 2; j <= F; j++) {
            dp[i][j] = 1000000;

            for (int k = 1; k <= j; k++) {
                int moves = 1 +
                    (dp[i - 1][k - 1] > dp[i][j - k]
                    ? dp[i - 1][k - 1]
                    : dp[i][j - k]);

                if (moves < dp[i][j])
                    dp[i][j] = moves;
            }
        }
    }

    printf("Minimum droppings = %d\n", dp[E][F]);

    return 0;
}