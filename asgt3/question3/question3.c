#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define CAR_AMOUNT 10
#define PARKING_SPACES 5
#define PARKING_TIME 5
#define CAR_DELAY 1

sem_t parking_spaces;
int spacesAvailable = PARKING_SPACES;

void* car(void* id) {
    int carId = *(int*)id;

    printf("Car %d arrived at the parking lot.\n", carId);

    sem_wait(&parking_spaces);
    printf("Car %d parked. Current open spots: %d\n", carId, --spacesAvailable);

    sleep(PARKING_TIME);

    sem_post(&parking_spaces);
    printf("Car %d left. Current open spots: %d\n", carId, ++spacesAvailable);

    return NULL;
}

int main() {
    pthread_t cars[CAR_AMOUNT];
    int carIds[CAR_AMOUNT];

    sem_init(&parking_spaces, 0, PARKING_SPACES);

    for (int i = 0; i < CAR_AMOUNT; i++) {
        carIds[i] = i+1;
        pthread_create(&cars[i], NULL, car, &carIds[i]);
        sleep(CAR_DELAY);
    }

    for (int j = 0; j < CAR_AMOUNT; j++) {
        pthread_join(cars[j], NULL);
    }

    sem_destroy(&parking_spaces);

    return 0;
}


