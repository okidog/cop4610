#include <stdio.h>
#include <pthread.h>

int collatz(int n) {
    int rVal = 0;

    if (n == 1) rVal = 1;
    else if (n % 2 == 0) rVal = n/2;
    else rVal = (3*n)+1;

    return rVal;
}

int main() {
    int n = 1;
    printf("Enter a number:\n"); // Scan user input
    scanf("%d", &n);

    while (n <= 0) { // Error checking for non-positive integers
        printf("Try again.\n");
        scanf("%d", &n);
    }

    printf("%d ", n);
    do {
        n = collatz(n);
        printf("%d ", n);
    } while (n != 1);

    return 0;
}