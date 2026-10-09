
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long nextValue(unsigned long long n) {
    if (n % 2 == 0)
        return n / 2;

    if (n > (ULLONG_MAX - 1) / 3)
        return 0;  // Overflow would occur

    return 3 * n + 1;
}

void analyse(unsigned long long n) {
    unsigned long long steps = 0, maxValue = n;
    printf("%llu: ", n);

    while (n != 1) {
        printf("%llu ", n);
        n = nextValue(n);

        if (n == 0) {
            printf("[overflow risk]\n");
            return;
        }

        steps++;
        if (n > maxValue)
            maxValue = n;
    }

    printf("1 | Steps = %llu, Maximum = %llu\n",
           steps, maxValue);
}

int main() {
    unsigned long long n, a, b;

    printf("Enter starting value n: ");
    scanf("%llu", &n);

    if (n == 0) {
        printf("Enter a positive integer.\n");
        return 1;
    }

    analyse(n);

    printf("Enter interval [a, b]: ");
    scanf("%llu %llu", &a, &b);

    if (a == 0 || a > b) {
        printf("Invalid interval.\n");
        return 1;
    }

    for (unsigned long long i = a; ; i++) {
        analyse(i);
        if (i == b)
            break;
    }

    return 0;
}
