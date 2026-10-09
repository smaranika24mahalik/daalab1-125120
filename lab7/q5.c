#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Number of spots must be greater than 1\n");
        return 0;
    }

    printf("No fixed sequence of shots guarantees a hit.\n");
    printf("The target can adapt its movements to avoid the shots.\n");

    return 0;
}