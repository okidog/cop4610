#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

int collatz(int n) {
    int rVal = 0;

    if (n == 1) rVal = 1;
    else if (n % 2 == 0) rVal = n/2;
    else rVal = (3*n)+1;

    return rVal;
}

int main() {
    pid_t pid;
    printf("The current process ID is: %d\n", pid);

    int n = 1;
    printf("Enter a number:\n"); // Scan user input
    scanf("%d", &n);

    while (n <= 0) { // Error checking for non-positive integers
        printf("Try again.\n");
        scanf("%d", &n);
    }

    pid = fork();
    printf("New child with process ID %d created\n", pid);
    if (pid == 0) {
        printf("%d ", n);
        do {
            n = collatz(n);
            printf("%d ", n);
        } while (n != 1);
    } else {
        printf("Waiting for child\n");
        wait(NULL);
    }
    return 0;
}