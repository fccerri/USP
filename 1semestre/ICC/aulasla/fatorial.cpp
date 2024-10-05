#include <stdio.h>

int main () {
    int n, resultado=1, i=1;
    scanf("%d", &n);

    while(i<=n) {
        resultado *= i;
        i++;
    }

    printf("%d", resultado);

    return 0;

}
