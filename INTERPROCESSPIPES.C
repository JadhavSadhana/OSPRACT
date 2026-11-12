PIPES.c

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int p1[2],p2[2];
    char filename[100],data[1000]={0};
    char buffer[100];

    pipe(p1);
    pipe(p2);

    if(fork()==0)
    {
        close(p1[1]);
        close(p2[0]);

        read(p1[0],filename,sizeof(filename));

        FILE *fp=fopen(filename,"r");
        if(fp)
        {
            while(fgets(buffer,sizeof(buffer),fp))
                strcat(data,buffer);
            fclose(fp);
        }
        else
            strcpy(data,"File not found");

        write(p2[1],data,sizeof(data));
        exit(0);
    }
    else
    {
        close(p1[0]);
        close(p2[1]);

        printf("Enter filename: ");
        scanf("%99s",filename);

        write(p1[1],filename,sizeof(filename));
        read(p2[0],data,sizeof(data));

        printf("File contents:\n%s\n",data);
        wait(NULL);
    }

    return 0;
}

Method to run:
nano pipes.c
gcc pipes.c -o pipes

Create a sample file:
echo "Welcome to Operating System" > test.txt
Run:
./pipes