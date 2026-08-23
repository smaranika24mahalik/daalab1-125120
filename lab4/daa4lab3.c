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

int findSum(int a[], int n, int k, int T,
            int start, int count, int sum)
{
    int i;

    if(count == k - 1)
    {
        int required = T - sum;

        return binarySearch(a, n, required);
    }

    for(i = start; i < n; i++)
    {
        if(findSum(a, n, k, T,
                   i + 1, count + 1, sum + a[i]))
            return 1;
    }

    return 0;
}

int main()
{
    int a[100], n, k, T, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%d", &T);

    sort(a, n);

    if(findSum(a, n, k, T, 0, 0, 0))
        printf("Yes, %d numbers add up to %d\n", k, T);
    else
        printf("No such combination exists.\n");

    return 0;
}