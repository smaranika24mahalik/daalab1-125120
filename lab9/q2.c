
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node *heap[MAX];
int size = 0;

void swap(struct Node **a, struct Node **b)
{
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

void insert(struct Node *x)
{
    int i = ++size;
    heap[i] = x;

    while(i > 1 && heap[i]->freq < heap[i/2]->freq)
    {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

struct Node *removeMin()
{
    struct Node *ans = heap[1];
    heap[1] = heap[size--];

    int i = 1;

    while(1)
    {
        int smallest = i;
        int l = 2*i, r = 2*i+1;

        if(l <= size && heap[l]->freq < heap[smallest]->freq)
            smallest = l;

        if(r <= size && heap[r]->freq < heap[smallest]->freq)
            smallest = r;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return ans;
}

int length[MAX];

void getLength(struct Node *root, int depth)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
        length[(unsigned char)root->ch] = depth ? depth : 1;
        return;
    }

    getLength(root->left, depth+1);
    getLength(root->right, depth+1);
}

void canonical()
{
    int order[MAX], n = 0, i, j;

    for(i = 0; i < MAX; i++)
        if(length[i] > 0)
            order[n++] = i;

    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(length[order[i]] > length[order[j]] ||
              (length[order[i]] == length[order[j]] &&
               order[i] > order[j]))
            {
                int t = order[i];
                order[i] = order[j];
                order[j] = t;
            }

    char code[MAX];
    int len = length[order[0]];

    for(i = 0; i < len; i++)
        code[i] = '0';

    code[len] = '\0';

    printf("\nCanonical Huffman Codes:\n");

    for(i = 0; i < n; i++)
    {
        if(i > 0)
        {
            int p = len-1;

            while(p >= 0 && code[p] == '1')
                code[p--] = '0';

            if(p >= 0)
                code[p] = '1';

            len = length[order[i]];

            while((int)strlen(code) < len)
            {
                int l = strlen(code);
                code[l] = '0';
                code[l+1] = '\0';
            }
        }

        printf("%c : %s\n", order[i], code);
    }
}

int main()
{
    int n, i, f;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        struct Node *x = malloc(sizeof(struct Node));

        printf("Enter character and frequency: ");
        scanf(" %c %d", &x->ch, &x->freq);

        x->left = x->right = NULL;
        insert(x);
    }

    while(size > 1)
    {
        struct Node *a = removeMin();
        struct Node *b = removeMin();

        struct Node *p = malloc(sizeof(struct Node));

        p->ch = '\0';
        p->freq = a->freq + b->freq;
        p->left = a;
        p->right = b;

        insert(p);
    }

    getLength(heap[1], 0);
    canonical();

    return 0;
}
