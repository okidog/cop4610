#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

# define BARISTA_COUNT 4

pthread_t baristas[BARISTA_COUNT];
pthread_mutex_t machines[BARISTA_COUNT];

float generateTime() {
    float randTime = rand() % 1000;
    randTime = randTime / 1000;
    return randTime;
}

void* barista(void* id) {
    int baristaId = *((int *)id);
    int leftMachine = baristaId;
    int centerMachine = (baristaId + 1) % BARISTA_COUNT;
    int rightMachine = (baristaId + 2) % BARISTA_COUNT;

    printf("Barista %d clocked in.\n", baristaId);

    while (1) {
        printf("Barista %d is waiting for the coffee machines...\n", baristaId);

        pthread_mutex_lock(&machines[leftMachine]);
        pthread_mutex_lock(&machines[centerMachine]);
        pthread_mutex_lock(&machines[rightMachine]);

        printf("Barista %d is making coffee...\n", baristaId);
        sleep(generateTime());

        pthread_mutex_unlock(&machines[leftMachine]);
        pthread_mutex_unlock(&machines[centerMachine]);
        pthread_mutex_unlock(&machines[rightMachine]);
        printf("Barista %d is done making coffee.\n", baristaId);
    }
}
int main() {
    srand(time(NULL));
    int baristaId[BARISTA_COUNT];

    for (int i = 0; i < BARISTA_COUNT; i++) {
        pthread_mutex_init(&machines[i], NULL);
        baristaId[i] = i;
        pthread_create(&baristas[i], NULL, barista, &baristaId[i]);
    }

    for (int i = 0; i < BARISTA_COUNT; i++) {
        pthread_join(baristas[i], NULL);
        pthread_mutex_destroy(&machines[i]);
    }

    return 0;
}