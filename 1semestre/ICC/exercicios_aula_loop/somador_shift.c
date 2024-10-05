#include <stdio.h>

int main (void) {
    int n1, n2, bit, result=0, saida;

    scanf("%d %d", &n1, &n2);
    
    while (n1) {
        n1--;
        scanf("%d", &bit);
        bit <<= n1;
        result += bit;
    }

    saida = result;
    result = 0;

    while (n2) {
        n2--;
        scanf("%d", &bit);

        bit <<= n2;
        result += bit;
    }

    saida += result;

    printf("%d\n", saida);

    return 0;
}