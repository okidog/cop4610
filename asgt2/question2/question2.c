#include <stdio.h>
#include <pthread.h>

int main() {
    int length = 0;
    printf("Set array length:\n"); // Handle input of array.
    scanf("%d", &length);
    int array[length+1];
    for (int i = 0; i < length; i++) {
        printf("Enter number %d:\n", i+1);
        scanf("%d", &array[i]);
        printf("%d", array[i]);
    }
    return 0;
}