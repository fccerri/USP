#include <stdio.h>
void swap(int *pa, int *pb) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main (void) {
    int a, b, *pa = &a, *pb = &b;
    scanf("%d%d", &a, &b);
    swap (pa, pb);

    printf("%d %d", *pa, *pb);
}

