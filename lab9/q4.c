
#include <stdio.h>

int main()
{
    int n, i, size = 0;
    int heap[1000];

    long long total = 0;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    printf("Enter stick lengths:\n");

    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        heap[++size] = x;

        int k = size;

        while(k > 1 && heap[k] < heap[k/2])
        {
            int t = heap[k];
            heap[k] = heap[k/2];
            heap[k/2] = t;
            k /= 2;
        }
    }

    while(size > 1)
    {
        int a = heap[1];
        heap[1] = heap[size--];

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

        int b = heap[1];
        heap[1] = heap[size--];

        k = 1;

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

        int sum = a+b;
        total += sum;

        heap[++size] = sum;

        k = size;

        while(k > 1 && heap[k] < heap[k/2])
        {
            int t = heap[k];
            heap[k] = heap[k/2];
            heap[k/2] = t;
            k /= 2;
        }
    }

    printf("Minimum cost = %lld\n", total);

    return 0;
}
