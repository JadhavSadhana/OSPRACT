
#include <stdio.h>

int main()
{
    int n,m,i,j,count=0;
    int a[10][10], max[10][10], need[10][10];
    int avail[10], finish[10]={0}, safe[10];

    printf("Enter processes and resources: ");
    scanf("%d%d",&n,&m);

    printf("Enter Allocation:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&a[i][j]);

    printf("Enter Maximum:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&max[i][j]);

    printf("Enter Available:\n");
    for(j=0;j<m;j++) scanf("%d",&avail[j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-a[i][j];

    while(count<n)
    {
        int found=0;
        for(i=0;i<n;i++)
        {
            if(!finish[i])
            {
                for(j=0;j<m && need[i][j]<=avail[j];j++);
                if(j==m)
                {
                    for(j=0;j<m;j++) avail[j]+=a[i][j];
                    safe[count++]=i;
                    finish[i]=found=1;
                }
            }
        }
        if(!found) break;
    }

    if(count==n)
    {
        printf("Safe Sequence: ");
        for(i=0;i<n;i++) printf("P%d ",safe[i]);
    }
    else printf("Unsafe State");

    return 0;
}

Method to run:
nano disk.c
gcc disk.c -o disk
./disk