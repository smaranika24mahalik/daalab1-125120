#include <stdio.h>

struct Result
{
    int min;
    int max;
};

struct Result findMinMax(int a[], int low, int high)
{
    struct Result result, left, right;

    // One element
    if (low == high)
    {
        result.min = a[low];
        result.max = a[low];
        return result;
    }

    // Two elements
    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            result.min = a[low];
            result.max = a[high];
        }
        else
        {
            result.min = a[high];
            result.max = a[low];
        }

        return result;
    }

    int mid = (low + high) / 2;

    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);

    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main()
{
    int a[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct Result result = findMinMax(a, 0, n - 1);

    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);

    return 0;
}