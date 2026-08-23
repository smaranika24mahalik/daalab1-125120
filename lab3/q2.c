#include <stdio.h>

int findDefective(int a[], int low, int high)
{
    if (low == high)
        return low;

    int mid = (low + high) / 2;

    int leftSum = 0;
    int rightSum = 0;

    for (int i = low; i <= mid; i++)
        leftSum += a[i];

    for (int i = mid + 1; i <= high; i++)
        rightSum += a[i];

    if (leftSum < rightSum)
        return findDefective(a, low, mid);

    else if (rightSum < leftSum)
        return findDefective(a, mid + 1, high);

    return -1;
}

int main()
{
    int a[100], n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter weights of coins:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int result = findDefective(a, 0, n - 1);

    if (result == -1)
        printf("No defective coin found.\n");
    else
        printf("Possible defective coin: %d\n", result + 1);

    return 0;
}