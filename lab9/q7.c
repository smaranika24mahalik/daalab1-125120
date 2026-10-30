
#include <stdio.h>

int main()
{
    int n, i, size = 0;

    int heap[1000];
    int min, ans = 1000000000;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        if(x % 2 != 0)
            x *= 2;

        if(i == 0 || x < min)
            min = x;

        heap[++size] = x;

        int k = size;

        while(k > 1 && heap[k] > heap[k/2])
        {
            int t = heap[k];
            heap[k] = heap[k/2];
            heap[k/2] = t;
            k /= 2;
        }
    }

    while(1)
    {
        int maximum = heap[1];

        if(maximum - min < ans)
            ans = maximum - min;

        // Stop if maximum is odd
        if(maximum % 2 != 0)
            break;

        int x = maximum / 2;

        if(x < min)
            min = x;

        heap[1] = x;

        int k = 1;

        while(2*k <= size)
        {
            int c = 2*k;

            if(c+1 <= size && heap[c+1] > heap[c])
                c++;

            if(heap[k] >= heap[c])
                break;

            int t = heap[k];
            heap[k] = heap[c];
            heap[c] = t;

            k = c;
        }
    }

    printf("Minimum deviation = %d\n", ans);

    return 0;
}
