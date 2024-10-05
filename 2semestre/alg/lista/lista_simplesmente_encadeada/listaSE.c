#include <iso646.h>
#include <stdlib.h>
#include "listaSE.h"
#include "item.h"



struct no_ {
    ITEM *item;
    NO *prox;
};

struct lista_se {
    int tamanho;
    NO *inicio, *fim;
} ;

NO *bb_menor_igual(LISTA_SE *lista, void *dado);

LISTA_SE *Lista_se_criar(void) {
    LISTA_SE *lista = malloc(sizeof(LISTA_SE));
    if (lista == NULL) exit(ERRO);

    lista->tamanho = 0;
    lista->inicio = NULL;  
    lista->fim = NULL; 
    
}

void lista_se_inserir(LISTA_SE *lista, ITEM *item) {
    if (lista == NULL ) return;

    NO *no = malloc(sizeof(NO));
    if (no == NULL) exit(ERRO);

    if (lista_se_vazia(lista)) lista->inicio = no;

    if (ORDENADA && !lista_se_vazia(lista) &&lista->tamanho != 1) {
        NO *aux = lista->inicio;

        while (*item_get_dados(aux->prox->item) < *item_get_dados(item)) //conferir
            aux = aux->prox;
        
        aux->prox = no;
        no->prox = aux->prox->prox;
    }
    else {
        lista->fim->prox = no; //add o no
        lista->fim = no; //reseta o fim
    }

    if (lista->tamanho == 1) {
                lista->inicio->prox = no;
                lista->fim = no;
            }
    no->item = item;

}

ITEM *lista_se_remover(LISTA_SE *lista, int chave) {
    if (lista == NULL || lista_se_vazia(lista)) return NULL;
    ITEM *it;

    NO *aux = lista->inicio; int ok = 1;
    if (item_get_chave(aux->item) == chave) ok = 0;
    while ((item_get_chave(aux->prox->item)) != chave && ok ) { //conferir
        aux = aux->prox;
        if (aux == lista->fim)  break;
    }

    if (item_get_chave(aux->item) != chave) return NULL;

    it = aux->prox->item;
    free(aux->prox);
    aux->prox = aux->prox->prox;  
    return it;  

}

void lista_se_apagar(LISTA_SE **lista) {
    if (lista == NULL) return;

    if (lista_se_vazia(*lista)) {
        free(*lista);
        *lista = NULL;
    }

    NO *temp, *aux = (*lista)->inicio;
    (*lista)->inicio = NULL;

    if((*lista)->tamanho == 1) {
        free((*lista)->inicio);
        (*lista)->inicio = NULL;
        (*lista)->fim = NULL;

        free(*lista);
        *lista = NULL;
        return;
    }

    while (aux->prox != (*lista)->fim) {
        temp = aux;
        free(aux);
        aux = temp->prox;
    }

    free(*lista);
    *lista = NULL;
}   

ITEM *lista_se_get_dados(LISTA_SE *lista, int chave) {
    if (lista == NULL || lista_se_vazia(lista)) return NULL;
    NO *aux = lista->inicio;
    if (lista->tamanho == 1) {
        if (item_get_chave(lista->inicio->item) == chave) return aux->item;
    }

    while
}
