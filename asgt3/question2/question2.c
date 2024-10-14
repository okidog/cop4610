#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

# define BARISTA_COUNT 4
# define BREWING_TIME 2

pthread_t baristas[BARISTA_COUNT]; // Init threads and mutex locks
pthread_mutex_t machines[BARISTA_COUNT];

void* barista(void* id) {
    int baristaId = *((int *)id); // Init resources for each barista, similar to forks in philosopher's dining problem
    int leftMachine = baristaId;
    int centerMachine = (baristaId + 1) % BARISTA_COUNT;
    int rightMachine = (baristaId + 2) % BARISTA_COUNT;

    printf("Barista %d clocked in.\n", baristaId); // Barista "starts" work

    while (1) {
        printf("Barista %d is waiting for the coffee machines...\n", baristaId);

        pthread_mutex_lock(&machines[leftMachine]);
        printf("Barista %d acquired the left machine.\n", baristaId);
        pthread_mutex_lock(&machines[centerMachine]);
        printf("Barista %d acquired the center machine.\n", baristaId);
        pthread_mutex_lock(&machines[rightMachine]);
        printf("Barista %d acquired the right machine.\n", baristaId);

        printf("Barista %d is making coffee...\n", baristaId);
        sleep(BREWING_TIME);

        pthread_mutex_unlock(&machines[leftMachine]);
        printf("Barista %d is done using the left machine.\n", baristaId); // Output lock releases
        pthread_mutex_unlock(&machines[centerMachine]);
        printf("Barista %d is done using the center machine.\n", baristaId);
        pthread_mutex_unlock(&machines[rightMachine]);
        printf("Barista %d is done using the right machine.\n", baristaId);

        printf("Barista %d is done making coffee.\n", baristaId); // Finished all tasks
    }

}
int main() {
    srand(time(NULL));
    int baristaId[BARISTA_COUNT];

    for (int i = 0; i < BARISTA_COUNT; i++) { // Create barista threads with readable IDs
        pthread_mutex_init(&machines[i], NULL);
        baristaId[i] = i;
        pthread_create(&baristas[i], NULL, barista, &baristaId[i]);
    }

    for (int i = 0; i < BARISTA_COUNT; i++) { // Join threads when done
        pthread_join(baristas[i], NULL);
        pthread_mutex_destroy(&machines[i]);
    }

    return 0;
}