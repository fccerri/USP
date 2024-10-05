#include <stdio.h> 
#include <stdlib.h>

int main() {
    int n; long long unsigned int *fib;

    printf("Quantos termos para a sequencia:\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Entrada Invalida");
        return 1;
    }

    fib = malloc(sizeof(long long unsigned int)*n);
    
    for (int i = 0; i<=n; i++) {
        if (i<=1) 
            fib[i] = 1;
        else {
            fib[i] = fib[i-1] + fib[i-2];
        }
        printf("fibonacci %d: %llu\n", i, fib[i]);
    }

    return 0;
}