#include <stdio.h>
#include <pthread.h>

int length = 0;
int totalRange, iqr, r = 0;

void *range(int array[]) {
    int maxNumber = 0;
    int minNumber = 2147000000;
    for (int i = 0; i <= length; i++) {
        if (array[i] <= minNumber) {minNumber = array[i];}
        else if (array[i] >= maxNumber) {maxNumber = array[i];}
    }
    totalRange = maxNumber - minNumber;
}

int main() {
    printf("Set array length:\n"); // Handle input of array.
    scanf("%d", &length);
    int array[length+1];
    for (int i = 0; i < length; i++) {
        printf("Enter number %d:\n", i+1);
        scanf("%d", &array[i]);
    }
    range(array);
    printf("%d", totalRange);

    return 0;
}