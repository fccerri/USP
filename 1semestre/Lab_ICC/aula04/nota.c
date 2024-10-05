#include <stdio.h>

int main (void) {
    float p1, p2, l1, l2, l3 ,l4, lista, final;

    scanf("%f %f %f %f %f %f", &p1, &p2, &l1, &l2, &l3 , &l4);

        lista = (l1+l2+l3+l4)/4;
        final = (p1+p2+lista)/3;

    if (final<3 || !lista) {
        printf("Reprovado");
        return 0;}

    else if (final<5 && final>=3) {
        printf("Recuperacao"); 
        return 0;}

    
    printf("Aprovado");


    return 0;
}