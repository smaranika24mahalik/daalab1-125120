#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Minimum moves = 0\n");
    } else {
        printf("Minimum moves = %d\n", n - 1);
    }

    return 0;
}