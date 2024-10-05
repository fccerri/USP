#include <stdio.h>

int soma (int n1, int n2) {
    if (!n2)
        return n1;
    
    return soma(n1, n2-1) + 1;
}

int main (void) {
    int n1, n2; scanf("%d%d", &n1, &n2);
    printf("%d", soma(n1, n2));

    return 0;
}