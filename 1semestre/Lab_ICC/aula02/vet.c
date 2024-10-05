#include <stdio.h>

int main () {
    long int n;
    scanf("%li", &n);

    printf("char: %li\n", sizeof(char)*n);
    printf("int: %li\n", sizeof(int)*n);
    printf("double: %li\n", sizeof(double)*n);


    return 0;
}