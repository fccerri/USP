#include <stdio.h>
#include <stdlib.h>

void *aloca(int tam) {
    double *p;
    p = (double*)malloc(tam*sizeof(double));
    if (p == NULL) {
        printf("da não\n");
        exit(1);
    }
    return p;
}

void entrada (double **vet, int *tam) {
    scanf("%d", tam);
    *vet = (double*)aloca(*tam);

    for (int i=0; i<*tam; i++) {
        scanf("%lf", vet[i]);
    }
}

void saida(double *vet, int tam ) {
    for (int i =0; i<tam; i++) {
        printf("%lf ", vet[i]);
    }
}


int main (void) {
    double *vet = NULL; int tam;

    entrada(&vet, &tam);

    saida(vet, tam);

    free(vet);
    vet = NULL;

    return 0;
}
