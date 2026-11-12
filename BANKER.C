
#include <stdio.h>

int main()
{
    int n,m,i,j,k;
    int alloc[10][10],max[10][10];
    int need[10][10],avail[10];
    int finish[10]={0},safe[10],count=0;

    printf("Enter processes and resources: ");
    scanf("%d%d",&n,&m);

    printf("Enter Allocation:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Maximum:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available resources:\n");
    for(j=0;j<m;j++)
        scanf("%d",&avail[j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    while(count<n)
    {
        int found=0;

        for(i=0;i<n;i++)
        {
            if(!finish[i])
            {
                for(j=0;j<m;j++)
                    if(need[i][j]>avail[j])
                        break;

                if(j==m)
                {
                    for(k=0;k<m;k++)
                        avail[k]+=alloc[i][k];

                    safe[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found) break;
    }

    if(count==n)
    {
        printf("Safe sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ",safe[i]);
    }
    else
        printf("Unsafe state");

    return 0;
}
TO RUN
nano banker.c
gcc banker.c -o banker
./banker