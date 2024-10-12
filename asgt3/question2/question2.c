#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


float generateTime() {
    float randTime = rand() % 1000;
    randTime = randTime / 1000;
    printf("Process will sleep for %f seconds\n", randTime);
    return randTime;
}

void leftMachine() {
    sleep(generateTime());
}

void centerMachine() {
    sleep(generateTime());
}

void rightMachine() {
    sleep(generateTime());
}

int main() {
    srand(time(NULL));
    leftMachine();
    centerMachine();
    rightMachine();
    return 0;
}