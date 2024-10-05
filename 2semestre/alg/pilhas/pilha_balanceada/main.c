#include <stdio.h> 
#include "Pilha.h"

int main () {
    char sequencia[1000]; int n;
    scanf("%d", &n);

    for (int i =0; i<n ; i++) {
        scanf(" %s", sequencia);

        if (balanceada(sequencia))
            printf("BALANCEADO\n");
        else
            printf("NÃO BALANCEADO\n");
    }
    return 0;
}