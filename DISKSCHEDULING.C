
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20],n,head,size,ch,i,j,t,move=0;
    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter initial head: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&size);

    printf("1.SSTF  2.SCAN  3.C-LOOK\n");
    scanf("%d",&ch);

    if(ch==1)
    {
        int done[20]={0},pos=head,best,d;
        for(i=0;i<n;i++)
        {
            best=-1;
            for(j=0;j<n;j++)
                if(!done[j] &&
                  (best==-1 || abs(a[j]-pos)<abs(a[best]-pos)))
                    best=j;

            d=abs(a[best]-pos);
            move+=d;
            pos=a[best];
            done[best]=1;
            printf("%d ",pos);
        }
    }
    else
    {
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i]>a[j])
                {
                    t=a[i];a[i]=a[j];a[j]=t;
                }

        printf("%d ",head);

        if(ch==2)
        {
            for(i=0;i<n;i++)
                if(a[i]>=head)
                {
                    move+=abs(a[i]-head);
                    head=a[i];
                    printf("%d ",head);
                }

            move+=abs((size-1)-head);
            head=size-1;
            printf("%d ",head);

            for(i=n-1;i>=0;i--)
                if(a[i]<head)
                {
                    move+=abs(a[i]-head);
                    head=a[i];
                    printf("%d ",head);
                }
        }
        else if(ch==3)
        {
            int first=1;
            for(i=0;i<n;i++)
                if(a[i]>=head)
                {
                    move+=abs(a[i]-head);
                    head=a[i];
                    printf("%d ",head);
                }
                else if(first)
                {
                    move+=abs(head-a[n-1]);
                    head=a[n-1];
                    printf("%d ",head);
                    first=0;
                    i=n;
                }

            for(i=0;i<n;i++)
                if(a[i]<head)
                {
                    move+=abs(a[i]-head);
                    head=a[i];
                    printf("%d ",head);
                }
        }
        else
        {
            printf("\nInvalid choice");
            return 0;
        }
    }

    printf("\nTotal head movement = %d\n",move);
    return 0;
}

Method to run:
nano disk.c
gcc disk.c -o disk
./disk