#include <stdio.h>
#define MAX 100040

void entrada(int *p, int vet[MAX]) {
    scanf("%d", p);

    for (int i = 0; i<(*p)-1; i++) {
        scanf("%d", &vet[i]);
    }
}

int resultado (int *p, int vet[MAX]) {
    int soma = 0;

    for (int i = 0; i<(*p)-1; i++) {
        soma += vet[i];
    }

    return (1+(*p))*(*p)/2 - soma;


    
}

int main (void) {
    int n, *p, vet[MAX];
    p = &n;

    entrada(p, vet);

    printf("Numero desaparecido: %d\n", resultado(p, vet));

    return 0;
}