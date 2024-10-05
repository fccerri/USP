#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista_t {
    int *numeros;
    int tam;
} lista_t;

void imprime (int *lista, int tam);

void guarda (int *lista, int tam, FILE *fp);

char geraNome (int tam);

int main (void) {
    lista_t lista;
    FILE *fp;

    srand(time(NULL)); //gera uma seed a partir do tempo
    scanf("%d", &lista.tam);

    lista.numeros = malloc(lista.tam*sizeof(int));

    for (int i =0; i<lista.tam; i++) {
        lista.numeros[i] = rand();
    }

    imprime(lista.numeros, lista.tam);
    free(lista.numeros);
    lista.numeros = NULL;

    return 0;
}

void imprime (int *lista, int tam) {
    for (int i =0; i<tam; i++) {
        printf("%d\n", lista[i]);
    }
}

void guarda (int *lista, int tam, FILE *fp, *char nome) {
    fp = fopen()

}

char geraNome (int tam) {
    char 
}

