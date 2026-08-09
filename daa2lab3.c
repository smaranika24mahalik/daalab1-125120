#include <stdio.h>
#include <stdlib.h>

void merge3(int a[], int l, int m1, int m2, int r)
{
    int temp[1000];
    int i = l, j = m1 + 1, k = m2 + 1, t = 0;

    while(i <= m1 && j <= m2 && k <= r)
    {
        if(a[i] <= a[j] && a[i] <= a[k])
            temp[t++] = a[i++];
        else if(a[j] <= a[i] && a[j] <= a[k])
            temp[t++] = a[j++];
        else
            temp[t++] = a[k++];
    }

    while(i <= m1 && j <= m2)
        temp[t++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while(j <= m2 && k <= r)
        temp[t++] = (a[j] < a[k]) ? a[j++] : a[k++];

    while(i <= m1 && k <= r)
        temp[t++] = (a[i] < a[k]) ? a[i++] : a[k++];

    while(i <= m1) temp[t++] = a[i++];
    while(j <= m2) temp[t++] = a[j++];
    while(k <= r) temp[t++] = a[k++];

    for(i = 0; i < t; i++)
        a[l + i] = temp[i];
}

void mergeSort3(int a[], int l, int r)
{
    if(l >= r)
        return;

    int third = (r - l) / 3;
    int m1 = l + third;
    int m2 = l + 2 * third + 1;

    if(m2 > r)
        m2 = r;

    mergeSort3(a, l, m1);
    mergeSort3(a, m1 + 1, m2);
    mergeSort3(a, m2 + 1, r);

    merge3(a, l, m1, m2, r);
}

int main()
{
    int a[] = {40, 20, 10, 50, 30, 60};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort3(a, 0, n - 1);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}