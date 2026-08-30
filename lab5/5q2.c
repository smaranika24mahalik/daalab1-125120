#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

int quickSelect(int a[], int low, int high, int k)
{
    if(low == high)
        return a[low];

    int p = partition(a, low, high);

    if(p == k)
        return a[p];

    else if(k < p)
        return quickSelect(a, low, p - 1, k);

    else
        return quickSelect(a, p + 1, high, k);
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if(k < 1 || k > n)
    {
        printf("Invalid K\n");
        return 0;
    }

    int answer = quickSelect(a, 0, n - 1, k - 1);

    printf("%dth smallest element = %d\n", k, answer);

    return 0;
}