#include <math.h>
#include <stdio.h>
#include <pthread.h>

int length = 0;
int totalRange = 0;
int iqr = 0;
float r = 0;

void range(int array[]) {
    int maxNumber = 0;
    int minNumber = 2147000000;
    for (int i = 0; i < length; i++) {
        if (array[i] <= minNumber) {minNumber = array[i];}
        if (array[i] >= maxNumber) {maxNumber = array[i];}
    }
    totalRange = maxNumber - minNumber;

    pthread_exit(NULL);
}

void insertionSort(int array[]) {
    for (int i = 1; i < length; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j>= 0 && array[j] > key) {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}

void interquartileRange(int array[]) {
        int thirdQuartileIndex = length * 0.75;
    if (length % 2 == 1) {
        int firstQuartile = array[length/4];
        int thirdQuartile = array[thirdQuartileIndex];
        iqr = thirdQuartile - firstQuartile;
    } else {
        int firstQSum = array[length/4 - 1] + array[(length/4)];
        int firstQuartile = (firstQSum/2);
        int thirdQSum = array[thirdQuartileIndex-1] + array[thirdQuartileIndex];
        int thirdQuartile = (thirdQSum/2);
        iqr = thirdQuartile - firstQuartile;
    }
    pthread_exit(NULL);
}

void stdDeviation(int array[]) {
    int mean = 0;
    int sum = 0;
    int sumOfSquares = 0;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    mean = sum/length;

    for (int i = 0; i < length; i++) {
        sumOfSquares += pow(array[i] - mean, 2);
    }
    int variance = sumOfSquares/length;
    r = sqrt(variance);

    pthread_exit(NULL);
}

int main() {
    printf("Set array length:\n"); // Handle input of array.
    scanf("%d", &length);
    int array[length];
    for (int i = 0; i < length; i++) {
        printf("Enter number %d:\n", i+1);
        scanf("%d", &array[i]);
    }

    insertionSort(array);

    pthread_t range_thread, iqr_thread, r_thread;
    pthread_create(&range_thread, NULL, range, array);
    pthread_create(&iqr_thread, NULL, interquartileRange, array);
    pthread_create(&r_thread, NULL, stdDeviation, array);

    pthread_join(range_thread, NULL);
    printf("Range of array: %d\n",totalRange);

    pthread_join(iqr_thread,NULL);
    printf("IQR of array is: %d\n", iqr);

    pthread_join(r_thread,NULL);
    printf("Standard deviation is: %f\n", r);

    return 0;
}