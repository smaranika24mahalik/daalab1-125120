#include <stdio.h>

int main()
{
    int n, i;
    int red[100], blue[100], yellow[100];
    int r = 0, b = 0, y = 0;
    int num;
    char color;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter number and colour (R/B/Y):\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d %c", &num, &color);

        if(color == 'R')
            red[r++] = num;
        else if(color == 'B')
            blue[b++] = num;
        else if(color == 'Y')
            yellow[y++] = num;
    }

    printf("Sorted by colour:\n");

    for(i = 0; i < r; i++)
        printf("%d R\n", red[i]);

    for(i = 0; i < b; i++)
        printf("%d B\n", blue[i]);

    for(i = 0; i < y; i++)
        printf("%d Y\n", yellow[i]);

    return 0;
}