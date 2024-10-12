#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphores.h>

#define CAR_AMOUNT 10
#define PARKING_SPACES 5

float generateTime() {
    float randTime = rand() % 50;
    randTime = randTime / 10;
    printf("Process will sleep for %f seconds\n", randTime);
    return randTime;
}


