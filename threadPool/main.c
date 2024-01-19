#include <stdio.h>
#include "threadPool.h"
#include <unistd.h>

#define MIN_THREADNUMS  3
#define MAX_THREADNUMS  10
#define MAX_QUEUE       10

void * threadHandleFunc(void *arg)
{
    threadPool * pool = (threadPool *)arg;
    for (int idx = 0; idx < 3; idx++)
    {
        usleep(100);
        printf("你好\n");
    }
    printf("busynum:%d\n", pool->busyThreadNums);
    printf("livenum:%d\n", pool->liveThreadNums);
    printf("\n");
    
    return NULL;
}

int main()
{
    threadPool pool;
    threadPoolInit(&pool, MIN_THREADNUMS, MAX_THREADNUMS, MAX_QUEUE);

    taskQueueInsert(&pool, threadHandleFunc, &pool);
    taskQueueInsert(&pool, threadHandleFunc, &pool);
    taskQueueInsert(&pool, threadHandleFunc, &pool);
    taskQueueInsert(&pool, threadHandleFunc, &pool);
    taskQueueInsert(&pool, threadHandleFunc, &pool);


    printf("taskqueue : %d\n", pool.queue->queueSize);
    printf("queue front : %d\n", pool.queue->front);
    printf("taskqueue: %d\n", pool.queue->rear);

    printf("livenum: %d\n", pool.liveThreadNums);
    printf("busynum: %d\n", pool.busyThreadNums);

    sleep(10);

    while (1)
    {
        printf("在等待.........\n");
        sleep(3);
    }

    return 0;
}