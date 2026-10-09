#include <stdio.h>

#define MAX 20

int dp[MAX + 1], split[MAX + 1];
int count3[MAX + 1];

void hanoi3(int n, char from, char to, char aux) {
    if (n == 0)
        return;

    hanoi3(n - 1, from, aux, to);
    printf("Move disk from %c to %c\n", from, to);
    hanoi3(n - 1, aux, to, from);
}

void hanoi4(int n, char from, char to,
            char aux1, char aux2) {
    if (n == 0)
        return;

    if (n == 1) {
        printf("Move disk from %c to %c\n", from, to);
        return;
    }

    int k = split[n];

    hanoi4(k, from, aux1, to, aux2);
    hanoi3(n - k, from, to, aux2);
    hanoi4(k, aux1, to, from, aux2);
}

int main() {
    int n, i, k;

    printf("Enter number of disks (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 0;

    for (i = 0; i <= n; i++)
        count3[i] = (1 << i) - 1;

    dp[0] = 0;
    dp[1] = 1;

    for (i = 2; i <= n; i++) {
        dp[i] = 1000000;

        for (k = 1; k < i; k++) {
            int moves = 2 * dp[k] + count3[i - k];

            if (moves < dp[i]) {
                dp[i] = moves;
                split[i] = k;
            }
        }
    }

    printf("Minimum moves = %d\n", dp[n]);
    hanoi4(n, 'A', 'D', 'B', 'C');

    return 0;
}