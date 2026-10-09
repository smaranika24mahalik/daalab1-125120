
#include <stdio.h>
#include <float.h>

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    double p[n + 1], q[n + 1];
    double e[n + 2][n + 1];
    double w[n + 2][n + 1];
    int root[n + 1][n + 1];

    printf("Enter successful probabilities p1 to pn: ");
    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);

    printf("Enter unsuccessful probabilities q0 to qn: ");
    for (int i = 0; i <= n; i++)
        scanf("%lf", &q[i]);

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; r++) {
                double cost = e[i][r - 1]
                            + e[r + 1][j] + w[i][j];

                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Minimum expected search cost = %.4f\n",
           e[1][n]);

    printf("Root key index = %d\n", root[1][n]);

    return 0;
}
