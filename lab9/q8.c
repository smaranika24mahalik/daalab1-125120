
#include <stdio.h>

struct Meeting
{
    int start, end;
};

int main()
{
    int n, i, j, size = 0;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    struct Meeting a[n];
    int heap[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter start and end: ");
        scanf("%d %d", &a[i].start, &a[i].end);
    }

    // Sort by start time
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i].start > a[j].start)
            {
                struct Meeting t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        // Reuse earliest available room
        if(size > 0 && heap[1] <= a[i].start)
        {
            heap[1] = a[i].end;

            int k = 1;

            while(2*k <= size)
            {
                int c = 2*k;

                if(c+1 <= size && heap[c+1] < heap[c])
                    c++;

                if(heap[k] <= heap[c])
                    break;

                int t = heap[k];
                heap[k] = heap[c];
                heap[c] = t;
                k = c;
            }
        }
        else
        {
            // Allocate new room
            heap[++size] = a[i].end;

            int k = size;

            while(k > 1 && heap[k] < heap[k/2])
            {
                int t = heap[k];
                heap[k] = heap[k/2];
                heap[k/2] = t;
                k /= 2;
            }
        }
    }

    printf("Minimum meeting rooms = %d\n", size);

    return 0;
}
