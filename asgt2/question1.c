#include <stdio.h>

int collatz(int n) {
    int rVal = 0;

    if (n == 1) rVal = 1;
    else if (n % 2 == 1) rVal = n/2;
    else rVal = (3*n)+1;

    return rVal;
}

int main() {
    int n = 1;
    printf("Enter a number:\n");
    scanf("%d", &n);
    do {
        n = collatz(n);
        printf("%p ", &n);
    } while (n != 1);
    return 0;
}