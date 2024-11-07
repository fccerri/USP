#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void radixSort(char **vet, int n);
void countingSort(char **vet, int n, int digito);

int main () {
    int n; scanf("%*d%d", &n);

    char **vet = malloc(sizeof(char*)*n); //aloca vetor
    for (int i = 0; i<n; i++) {
        vet[i] = calloc(4, sizeof(char)); //aloca numeros
        scanf(" %s", vet[i]); //guarda no vetor o valor da string
    }

    radixSort(vet, n);

    for (int i = 0; i<n; i++) {
        printf("%s ", vet[i]); //printa vetor ordenado
        free(vet[i]); //libera memoria
        vet[i] = NULL;
    }
    free(vet);
    vet = NULL;

    return 0;
}

void radixSort(char **vet, int n) {
    int size = strlen(vet[0]);
    for (int i = 1; i<= size; i++) {
        countingSort(vet, n, size-i);
    }
}

void countingSort(char **vet, int n, int digito) {
    int count[16] = {0}; // Contador para dígitos de 0 a 16
    int num; //digito relevante de cada numero
    char **output = malloc(n * sizeof(char*)); //vetor que aponta para as strings ja alocadas de vet

    for (int i = 0; i < n; i++) {
        if (vet[i][digito] >= '0' && vet[i][digito] <= '9')
            num = vet[i][digito] - '0'; // Extrai o dígito relevante
        else 
            num = vet[i][digito] - 'A' + 10; // Extrai o dígito relevante

        count[num]++;
    }

    for (int i = 1; i < 16; i++) {
        count[i] += count[i - 1]; // faz o prefix
    }

    for (int i = n - 1; i >= 0; i--) {
        if (vet[i][digito] >= '0' && vet[i][digito] <= '9')
            num = vet[i][digito] - '0'; // Extrai o dígito relevante
        else 
            num = vet[i][digito] - 'A' + 10; // Extrai o dígito relevante

        output[count[num] - 1] = vet[i]; //determina a ordenacao do digito relevante
        count[num]--; //ajusta o prefix
    }

    for (int i = 0; i < n; i++) { //copia a ordenacao para o vetor 
        vet[i] = output[i];
    }

    free(output);
}