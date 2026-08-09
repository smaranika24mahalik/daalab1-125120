#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;

void insert(int value)
{
    arr[n++] = value;
}

void search(int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not Found\n");
}

void deleteElement(int key)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            for(j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];

            n--;
            printf("Deleted Successfully\n");
            return;
        }
    }

    printf("Element Not Found\n");
}

void maximum()
{
    int i, max = arr[0];

    for(i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];

    printf("Maximum = %d\n", max);
}

void minimum()
{
    int i, min = arr[0];

    for(i = 1; i < n; i++)
        if(arr[i] < min)
            min = arr[i];

    printf("Minimum = %d\n", min);
}

void display()
{
    int i;

    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    insert(20);
    insert(5);
    insert(15);
    insert(40);
    insert(10);

    display();

    search(15);

    maximum();

    minimum();

    deleteElement(15);

    display();

    return 0;
}