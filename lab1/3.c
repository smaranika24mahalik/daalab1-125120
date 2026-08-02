#include<stdio.h>

int main()
{
    int n,i,j,temp,swap;
    int count=0;

    printf("Enter size: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n-1;i++)
    {
        swap=0;

        for(j=0;j<n-i-1;j++)
        {
            count++;

            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swap=1;
            }
        }

        if(swap==0)
            break;
    }

    printf("Sorted array:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nComparisons=%d",count);

    return 0;
}
