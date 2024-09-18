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

    printf("Range of array: %d\n",totalRange);

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
        int firstQuartile = ((array[length/4] + array[(length/4) + 1])/2);
        int thirdQuartile = ((array[thirdQuartileIndex] + array[thirdQuartileIndex+1])/2);
        iqr = thirdQuartile - firstQuartile;
    }

    printf("IQR of array is: %d\n", iqr);
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
    r = powf(sumOfSquares/length, 1/2);
    printf("Standard deviation is: %f\n", r);
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

    range(array);
    interquartileRange(array);
    stdDeviation(array);

    return 0;
}