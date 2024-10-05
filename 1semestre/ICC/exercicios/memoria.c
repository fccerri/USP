#include <stdio.h>

int main () {
    long long int saida=0;
    unsigned short int a , b, c;
    scanf("%hd %hd %hd", &a, &b, &c);

    saida = c;
    saida <<= 16;

    saida += b;
    saida <<= 16;
  
    saida += a;

    printf("%lld\n", saida);

    return 0;
}