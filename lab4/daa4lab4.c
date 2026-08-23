#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
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
    int entry[100], exit[100];
    int n, i;
    int e = 0, x = 0;
    int people = 0, maxPeople = 0;
    int maxTime = 0;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter entry and exit time:\n");

    for(i = 0; i < n; i++)
        scanf("%d %d", &entry[i], &exit[i]);

    sort(entry, n);
    sort(exit, n);

    while(e < n && x < n)
    {
        if(entry[e] < exit[x])
        {
            people++;

            if(people > maxPeople)
            {
                maxPeople = people;
                maxTime = entry[e];
            }

            e++;
        }
        else
        {
            people--;
            x++;
        }
    }

    printf("Maximum people = %d\n", maxPeople);
    printf("Time = %d\n", maxTime);

    return 0;
}