
#include <stdio.h>
#include <string.h>

#define MAX 1000

struct Node
{
    char ch;
    int count;
};

struct Node heap[MAX], wait[MAX];

int size = 0;

void insert(struct Node x)
{
    int i = ++size;
    heap[i] = x;

    while(i > 1 && heap[i].count > heap[i/2].count)
    {
        struct Node t = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = t;
        i /= 2;
    }
}

struct Node removeMax()
{
    struct Node ans = heap[1];
    heap[1] = heap[size--];

    int i = 1;

    while(2*i <= size)
    {
        int c = 2*i;

        if(c+1 <= size && heap[c+1].count > heap[c].count)
            c++;

        if(heap[i].count >= heap[c].count)
            break;

        struct Node t = heap[i];
        heap[i] = heap[c];
        heap[c] = t;

        i = c;
    }

    return ans;
}

int main()
{
    char s[MAX], result[MAX];
    int k, freq[256] = {0};
    int i, n, front = 0, rear = 0;

    printf("Enter string: ");
    scanf("%999s", s);

    printf("Enter K: ");
    scanf("%d", &k);

    n = strlen(s);

    for(i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    for(i = 0; i < 256; i++)
    {
        if(freq[i] > 0)
        {
            struct Node x;
            x.ch = i;
            x.count = freq[i];
            insert(x);
        }
    }

    int pos = 0;

    while(pos < n)
    {
        // Release characters whose cooldown is over
        while(front < rear && front + k <= pos)
            insert(wait[front++]);

        if(size == 0)
        {
            printf("Reorganisation impossible\n");
            return 0;
        }

        struct Node x = removeMax();

        result[pos++] = x.ch;
        x.count--;

        if(x.count > 0)
            wait[rear++] = x;
    }

    result[pos] = '\0';

    printf("Reorganised string: %s\n", result);

    return 0;
}
