#include <stdio.h>

int main (void) {
    int n, *p = &n, **pp = &p;

    scanf("%d", &n);

    printf("Valor inicial da variavel: %d\n", n);
    printf("Valor do ponteiro antes do incremento: %d\n", *p);

    *p += 10;

    printf("Valor do ponteiro depois do incremento: %d\n", *p);
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **pp);

    **pp += 10;

    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **pp);
    printf("Valor final da variavel: %d\n", n);
    
    return 0;                   
    

}