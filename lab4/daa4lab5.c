#include <stdio.h>

struct Interval
{
    int start;
    int end;
};

void sort(struct Interval a[], int n)
{
    int i, j;
    struct Interval temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i].start > a[j].start)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    struct Interval a[100], result[100];

    int n, i, m = 0;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter intervals:\n");

    for(i = 0; i < n; i++)
        scanf("%d %d", &a[i].start, &a[i].end);

    sort(a, n);

    result[m++] = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i].start <= result[m - 1].end)
        {
            if(a[i].end > result[m - 1].end)
                result[m - 1].end = a[i].end;
        }
        else
        {
            result[m++] = a[i];
        }
    }

    printf("Merged intervals:\n");

    for(i = 0; i < m; i++)
        printf("(%d, %d)\n",
               result[i].start,
               result[i].end);

    return 0;
}