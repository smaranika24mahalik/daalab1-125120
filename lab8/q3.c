
#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100], lcs[100];
    int dp[100][100];

    printf("Enter first string: ");
    scanf("%99s", a);
    printf("Enter second string: ");
    scanf("%99s", b);

    int m = strlen(a), n = strlen(b);

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    int i = m, j = n, k = dp[m][n];
    lcs[k] = '\0';

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[--k] = a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS length = %d\n", dp[m][n]);
    printf("LCS = %s\n", lcs);

    return 0;
}
