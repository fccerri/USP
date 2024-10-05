#include <stdio.h>


int main (void) {
    int bitmap = 0, n, manobra;
    char caracter;
    scanf("%d", &n);

    for (int i =0; i< n; i++) {
        scanf(" %c", &caracter); 
        manobra = 1;
        caracter -= 97;
        bitmap ^= (manobra <<= caracter); 
    }

    if ((bitmap & (bitmap-1)) == 0)
        printf("Sim\n");
    
    else printf("Nao\n");

    return 0;
}