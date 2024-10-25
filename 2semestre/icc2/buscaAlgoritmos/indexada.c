#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct item_ {
    int valor;
    int chave;
} item;

void insercao(item vet[], item dado, int *tam) {
    if (*tam < MAX || vet != NULL) {
        vet[*tam] = dado;
        (*tam)++;
    }
}

bool remocao(item vet[], int *tam, int chave) {
    for (int i =0; i < *tam; i++) {
        if (chave == vet[i].chave) {
            for (int j = i; j < (*tam)-1; j++) {
                vet[j] = vet[j+1];
            }

            (*tam)--;
            return true;
        }
    }
    return false;
}

void print(item vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("valor: %d, chave: %d\n", vet[i].valor, vet[i].chave);
    }
}

int main () {
    int tam = 0; char op; item vet[MAX], aux;
    printf("Para inserir: i <valor> <chave>\n");
    printf("Para remover: r <chave>\n");
    printf("Para printar: p\n");
    printf("Para encerrar: q\n");

    while(true) {
        scanf(" %c", &op);
        switch (op) {
            case ('i'): {
                scanf("%d%d", &aux.valor, &aux.chave);
                insercao(vet, aux, &tam);
                break;
            }

            case ('r'): {
                if (remocao(vet, &tam, aux.chave))
                    printf("Item com chave %d removido.\n", aux.chave);
                else 
                    printf("Chave %d não encontrada.\n", aux.chave);
                
                break;
            }

            case ('p'): {
                print(vet, tam);
                break;
            }

            case ('q'): return 0;
        }   
    }
}