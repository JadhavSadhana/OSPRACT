
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer, item = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    for(int i=1;i<=5;i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer=i;
        printf("Produced: %d\n",buffer);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg)
{
    for(int i=1;i<=5;i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item=buffer;
        printf("Consumed: %d\n",item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main()
{
    pthread_t p,c;

    sem_init(&empty,0,1);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    return 0;
}
TO RUN 
nano producer.c
gcc producer.c -o producer -pthread
./producer