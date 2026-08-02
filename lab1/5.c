#include<stdio.h>

int main()
{
    int n,i;

    printf("Enter size: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter 0s followed by 1s:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    int low=0,high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(a[mid]==0 && a[mid+1]==1)
        {
            printf("Partition Index=%d\n",mid);
            return 0;
        }

        if(a[mid]==0)
            low=mid+1;
        else
            high=mid-1;
    }

    return 0;
}
