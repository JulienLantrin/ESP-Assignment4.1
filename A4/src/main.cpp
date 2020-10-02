#include <iostream>
//using namespace std; //Other way to use the standard library
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fifo.h>

pthread_mutex_t sharedVariableMutex;
int32_t gSharedVariable=0;
pthread_t incrementTaskObj;
pthread_t decrementTaskObj;
Fifo fifo;

void* incrementTask(void *param);
void* decrementTask(void *param);

// void* incrementTask(void *param){
//     while(1){
//         /*Delayfor3seconds.*/
//         sleep(3);
//         /*Waitforthemutextobecomeavailable.*/
//         pthread_mutex_lock(&sharedVariableMutex);
//         gSharedVariable++;
//         printf("IncrementTask: %d \n",gSharedVariable);
//         /*Releasethemutexforothertasktouse.*/
//         pthread_mutex_unlock(&sharedVariableMutex);
//     }
// }

// void *decrementTask(void *param){
//     while(1){
//         /*Delayfor3seconds.*/
//         sleep(7);
//         /*Waitforthemutextobecomeavailable.*/
//         pthread_mutex_lock(&sharedVariableMutex);
//         gSharedVariable--;
//         printf("DecrementTask: %d \n",gSharedVariable);
//         /*Releasethemutexforothertasktouse.*/
//         pthread_mutex_unlock(&sharedVariableMutex);
//     }
// }

int main(void){
    /*Createthemutexforaccessingthesharedvariableusingthe*defaultattributes.*/
    pthread_mutex_init(&sharedVariableMutex, NULL);
    /*Createtheincrementanddecrementtasksusingthedefaulttask*attributes.Donotpassinanyparameterstothetasks.*/
    pthread_create(&incrementTaskObj, NULL, incrementTask, NULL);
    pthread_create(&decrementTaskObj, NULL, decrementTask, NULL);
    /*Allowthetaskstorun.*/
    pthread_join(incrementTaskObj, NULL);
    pthread_join(decrementTaskObj, NULL);
    return 0;
}