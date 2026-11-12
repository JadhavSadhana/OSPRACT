
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int a[5], i, j, t;
    pid_t pid;

    printf("Enter 5 numbers: ");
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);

    pid = fork();

    if(pid == 0)
    {
        for(i=0;i<5;i++)
            for(j=i+1;j<5;j++)
                if(a[i] > a[j])
                {
                    t=a[i]; a[i]=a[j]; a[j]=t;
                }

        printf("Child sorted: ");
        for(i=0;i<5;i++) printf("%d ",a[i]);
        printf("\n");
        exit(0);
    }
    else if(pid > 0)
    {
        wait(NULL);

        for(i=0;i<5;i++)
            for(j=i+1;j<5;j++)
                if(a[i] < a[j])
                {
                    t=a[i]; a[i]=a[j]; a[j]=t;
                }

        printf("Parent sorted: ");
        for(i=0;i<5;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
TO RUN
nano process.c
gcc process.c -o process
./process