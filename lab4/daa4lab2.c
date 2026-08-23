#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
            return 1;

        if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main()
{
    int S1[100], S2[100];
    int n, x, i, target;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter S1:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &S1[i]);

    printf("Enter S2:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    sort(S2, n);

    for(i = 0; i < n; i++)
    {
        target = x - S1[i];

        if(binarySearch(S2, n, target))
        {
            printf("Pair exists: %d + %d = %d\n",
                   S1[i], target, x);
            return 0;
        }
    }

    printf("No pair exists.\n");

    return 0;
}