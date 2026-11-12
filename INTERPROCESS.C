FIFO1.C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char msg[100],reply[100];
    mkfifo("pipe1",0666);
    mkfifo("pipe2",0666);

    int w=open("pipe1",O_WRONLY);
    int r=open("pipe2",O_RDONLY);

    printf("Enter sentence: ");
    fgets(msg,100,stdin);
    write(w,msg,sizeof(msg));

    read(r,reply,sizeof(reply));
    printf("Reply: %s",reply);

    close(w);
    close(r);
    return 0;
}


FIFO2.c

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char msg[100],reply[100];
    mkfifo("pipe1",0666);
    mkfifo("pipe2",0666);

    int r=open("pipe1",O_RDONLY);
    int w=open("pipe2",O_WRONLY);

    read(r,msg,sizeof(msg));

    int chars=0,words=0,lines=0;
    for(int i=0;msg[i];i++)
    {
        if(msg[i]!=' ' && msg[i]!='\n')
            chars++;
        if(msg[i]==' ')
            words++;
        if(msg[i]=='\n')
            lines++;
    }
    if(chars) words++;

    printf("Message: %s",msg);
    sprintf(reply,"Characters=%d Words=%d Lines=%d",
            chars,words,lines);

    write(w,reply,sizeof(reply));

    close(r);
    close(w);
    return 0;
}

TO RUN IN 1ST TERMINAL
gcc fifo1.c -o fifo1
gcc fifo2.c -o fifo2
./fifo1
THEN OPEN 2ND TERMINAL
./fifo2