#include <stdio.h>

struct Event
{
    int point;
    int type;
};

void sort(struct Event e[], int n)
{
    int i, j;
    struct Event temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(e[i].point > e[j].point ||
              (e[i].point == e[j].point &&
               e[i].type < e[j].type))
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

int main()
{
    struct Event e[200];

    int n, i;
    int count = 0;
    int maxCount = 0;
    int maxPoint = 0;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter intervals:\n");

    for(i = 0; i < n; i++)
    {
        int l, r;

        scanf("%d %d", &l, &r);

        e[2*i].point = l;
        e[2*i].type = 1;

        e[2*i + 1].point = r;
        e[2*i + 1].type = -1;
    }

    sort(e, 2*n);

    for(i = 0; i < 2*n; i++)
    {
        count += e[i].type;

        if(count > maxCount)
        {
            maxCount = count;
            maxPoint = e[i].point;
        }
    }

    printf("Point = %d\n", maxPoint);
    printf("Maximum overlapping intervals = %d\n", maxCount);

    return 0;
}
