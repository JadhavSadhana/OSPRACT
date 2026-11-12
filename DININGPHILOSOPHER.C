
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t room;
pthread_mutex_t fork[5];

void *philosopher(void *n)
{
    int id=*(int *)n;

    sem_wait(&room);

    pthread_mutex_lock(&fork[id]);
    pthread_mutex_lock(&fork[(id+1)%5]);

    printf("Philosopher %d is eating\n",id);
    sleep(1);

    pthread_mutex_unlock(&fork[(id+1)%5]);
    pthread_mutex_unlock(&fork[id]);

    sem_post(&room);

    printf("Philosopher %d is thinking\n",id);
    return NULL;
}

int main()
{
    pthread_t t[5];
    int id[5];

    sem_init(&room,0,4);

    for(int i=0;i<5;i++)
    {
        pthread_mutex_init(&fork[i],NULL);
        id[i]=i;
    }

    for(int i=0;i<5;i++)
        pthread_create(&t[i],NULL,philosopher,&id[i]);

    for(int i=0;i<5;i++)
        pthread_join(t[i],NULL);

    return 0;
}
TO RUNnano dining.c
gcc dining.c -o dining -pthread
./dining