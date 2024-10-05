#include <stdio.h>

void ordene(int *pa, int *pb, int *pc);

void swap (int *p1, int *p2);

int main (void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int *pa = &a, *pb = &b, *pc = &c;

    ordene(pa, pb, pc);

    printf("%d %d %d", a, b, c);
}

void ordene(int *pa, int *pb, int *pc) { //rdena por bubble
    if (*pa > *pb) swap (pa, pb);
    if (*pb > *pc) swap (pb, pc);
    if (*pa > *pb) swap (pa, pb);
}

void swap (int *p1, int *p2) { //troca duas variaveis
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

