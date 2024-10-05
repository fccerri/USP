#include <stdio.h>

int fibonacci(int n);

/*memset: define os primeiros n bytes da area de memoria 
apontadas por s para o vaor c
 -- void *memset(void *s, int c, size_t n);

 - memcpy: copia os primeiros n bytes dda memoria src para a aére de memoria dest
   - void *memcpy(void *dest, conts void *src, size_t n);

*/

int main () { //definir quantos termos para a sequencia 
    int n;

    printf("Quantos termos para a sequencia:\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Entrada Invalida");
        return 1;
    }

    for (int i = 0; i<=n; i++) {
        printf("fibonacci %d: %d\n", i, fibonacci(i));
    }

    

    return 0;
}

int fibonacci(int n) {
    if (n==0 || n== 1)
        return 1;

    return fibonacci(n-1) + fibonacci (n-2);
}