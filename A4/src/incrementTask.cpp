#include <pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
#include <fifo.h>

extern pthread_mutex_t sharedVariableMutex;
extern int32_t gSharedVariable;
extern Fifo fifo;
int c = 0;

void* incrementTask(void *param){
    while(1){
        /*Delayfor3seconds.*/
        sleep(3);
        /*Waitforthemutextobecomeavailable.*/
        pthread_mutex_lock(&sharedVariableMutex);
        fifo.put(c);
        c++;
        printf("Fifo_i: %d %d %d %d %d \n",fifo.buffer[0],fifo.buffer[1],fifo.buffer[2],fifo.buffer[3],fifo.buffer[4]);
        /*Releasethemutexforothertasktouse.*/
        pthread_mutex_unlock(&sharedVariableMutex);
    }
}