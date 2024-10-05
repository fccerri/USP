#include <stdio.h>

int main () {
    int l1, l2, l3, l4;

    scanf("%d %d %d %d", &l1, &l2, &l3, &l4);

    if (!(l1+l2+l3+l4)) {
        printf("nenhum!\n");
        return 0;
    }

    if (l1==l2 && l2==l3 && l3==l4) {
        printf("quadrado!\n"); 
        return 0;}

    if ((l1==l4 && l2==l3) || (l1==l3 && l2==l4)) {
        printf("retangulo!\n");
        return 0;}



    printf("nenhum!\n");
    

    return 0;
}