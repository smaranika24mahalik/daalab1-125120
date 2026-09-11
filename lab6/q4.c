#include <stdio.h>

void reverse(int a[], int i, int j) {

    while(i < j) {

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
}

int main() {

    int a[100], n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter permutation:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);


    // Put correct element at every position
    for(int i = 0; i < n; i++) {

        if(a[i] == i + 1)
            continue;

        int pos;

        // Find i+1
        for(pos = i + 1; pos < n; pos++) {
            if(a[pos] == i + 1)
                break;
        }

        // Reverse the required part
        reverse(a, i, pos);
    }


    printf("Sorted permutation:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}