#include <stdio.h>
#include <math.h>

int main() {
    int a[100], n, i, j;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // 1. Maximum
    int max = a[0];

    for(i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
    }

    printf("Maximum = %d\n", max);


    // 2. First and second largest
    int largest = a[0];
    int second = -999999;

    for(i = 1; i < n; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", second);


    // 3. Mean
    float sum = 0;

    for(i = 0; i < n; i++)
        sum += a[i];

    float mean = sum / n;

    printf("Mean = %.2f\n", mean);


    // 4. Standard deviation
    float variance = 0;

    for(i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance = variance / n;

    printf("Standard Deviation = %.2f\n", sqrt(variance));


    // 5. Mode
    int mode = a[0];
    int maxCount = 0;

    for(i = 0; i < n; i++) {
        int count = 0;

        for(j = 0; j < n; j++) {
            if(a[i] == a[j])
                count++;
        }

        if(count > maxCount) {
            maxCount = count;
            mode = a[i];
        }
    }

    printf("Mode = %d\n", mode);


    // 6. Reverse
    int temp;

    for(i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }

    printf("Reversed array: ");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}