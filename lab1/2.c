#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n,i;
    int head=0;

    printf("Enter number of tosses: ");
    scanf("%d",&n);

    srand(time(NULL));

    for(i=0;i<n;i++)
    {
        if(rand()%2)
            head++;
    }

    printf("Fair Coin Probability = %.2f\n",(float)head/n);

    head=0;

    for(i=0;i<n;i++)
    {
        if(rand()%100<70)
            head++;
    }

    printf("Biased Coin Probability = %.2f\n",(float)head/n);

    return 0;
}
