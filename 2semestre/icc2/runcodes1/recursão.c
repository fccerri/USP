#include <stdio.h>
#define TAM 100

int potencia(int b, int e);

void entrada(int vet[TAM], int n);

int soma(int vet[TAM], int inf, int sup);

void inverte(int vet[TAM], int inf, int sup);

int main () {
    char c; int result, n, n2, b, e, vet[TAM]; 
    scanf("%d", &n);

    for (int i = 0; i<n; i++) {
        scanf(" %c", &c);

        switch (c) {
            case 'P' : {
                scanf("%d%d", &b, &e);

                result = potencia(b, e);
                printf("%d\n", result);
                break;
            }
            case 'S' :{
                scanf("%d", &n2); 
                entrada(vet, n2);

                result = soma(vet, 0, n2-1);
                printf("%d\n", result);
                break;
            }
            case 'I' :{
                scanf("%d", &n2); 
                entrada(vet, n2);

                inverte(vet, 0, n2-1);
                for (int i =0; i<n2; i++) {
                    printf("%d ", vet[i]);
                }
                printf("\n"); break;

            }
        }
    }

}

int soma(int vet[TAM], int inf, int sup) {
    if (inf > sup) return 0;

    return vet[inf] + soma(vet, inf+1, sup);
}

void inverte(int vet[TAM], int inf, int sup) {
    if (inf >= sup) return;

    int temp = vet[inf];
    vet[inf] = vet[sup];
    vet[sup] = temp;

    inverte(vet, inf+1, sup-1); 
}

int potencia(int b, int e) {
    if (e == 1) return b;
    if (e == 0) return 1;

    return b*potencia(b, e-1);
}

void entrada(int vet[TAM], int n) {
    for (int i =0; i< n; i++) {
        scanf("%d", &vet[i]);
    }
}

