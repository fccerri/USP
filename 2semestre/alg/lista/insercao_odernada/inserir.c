#include "item.h"
#include "lista.h"
#include "stdlib.h"
#include <stdio.h>
#ifndef STRUCTS_

#define STRUCTS_

struct lista_{ 

    ITEM *lista[TAM_MAX];

    int inicio; // pos do primeiro item

    int fim; // pos do próximo espaço vazio

    int tamanho;

};

#endif

int busca_binaria(int valor, int inicio, int fim, LISTA *lista) {
    int n = (inicio + fim ) / 2;

    if (inicio == fim) {
        return inicio;
    }

    if (valor <= item_get_chave(lista->lista[n]) )
        return busca_binaria(valor, inicio, n, lista);
    
    else  
        return busca_binaria(valor, n+1, fim, lista);
}

bool lista_inserir(LISTA *lista, ITEM *item) {
    if (lista == NULL || lista->tamanho == TAM_MAX) return 0;

    int valor = item_get_chave(item), inicio = (lista->inicio), fim = (lista->fim);

	int id = busca_binaria(valor, inicio, fim, lista); //acha posicao

    for (int i = fim; i>=id; i--) { //deslocamento
        lista->lista[i] = lista->lista[i-1];
    }

    lista->lista[id] = item; //ajuste da lista
    lista->tamanho++;
    lista->fim++;

    return 1;
}

