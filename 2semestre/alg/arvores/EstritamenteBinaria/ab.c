#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include "ab.h"


typedef struct no_ {
    struct no_ *filho_esq;
    struct no_ *filho_dir;
    ITEM *dados;
} NO;

struct arv_bin {
    NO *raiz;
    int estritamenteBinaria;
};

void imprime_caminho(NO *raiz);


NO *acha_no(NO *raiz, int chave) {
    if (raiz == NULL) return NULL; //caso não encontre
    int chave_aux = item_get_chave(raiz->dados); 
    if (chave_aux == chave) return raiz; //caso o valor tenha sido encontrado

    NO *no_aux = acha_no(raiz->filho_esq, chave); //chama função para filhos da esquerda

    if (no_aux != NULL) return no_aux; //caso o valor ja tenha sido encontrado anteriormente

    return acha_no(raiz->filho_dir, chave); //chama função para filhos da direita
}
 
 
AB *ab_criar(void) {
    AB *aux = malloc(sizeof(AB));
    aux->raiz = NULL;
    aux->estritamenteBinaria = 0;
    return aux; 
}

bool ab_inserir (AB *T, ITEM *item, int lado, int chave) {
    NO *no_de_insercao = acha_no(T->raiz, chave);
    if (T->raiz == NULL) no_de_insercao = T->raiz;

    if (no_de_insercao != NULL  ) {
        NO *filho = malloc(sizeof(NO));
        filho->dados = item;
        filho->filho_dir =NULL;
        filho->filho_esq =NULL;

        if (lado == FILHO_DIR) 
            no_de_insercao->filho_dir = filho;
        else 
            no_de_insercao->filho_esq = filho;

        if (no_de_insercao->filho_dir == NULL || no_de_insercao->filho_esq == NULL)
            (T->estritamenteBinaria)++;
        else
            (T->estritamenteBinaria)--;

        imprime_caminho(no_de_insercao);
        printf("\n");
        imprime_caminho(T->raiz);


        return 1;
    }
    return 0;

}

void imprime_caminho(NO *raiz) {
    if (raiz == NULL) return;
    printf("%d", item_get_chave(raiz->dados));
    imprime_caminho(raiz->filho_esq);
    imprime_caminho(raiz->filho_dir);
}

void ab_imprimir (AB *T) {
    if (T == NULL) return;
   imprime_caminho(T->raiz);

}

void apaga_nos(NO **raiz) {
    if (*raiz != NULL) {
        apaga_nos(&(*raiz)->filho_dir); //chamada recursiva para arvore da direita
        apaga_nos(&(*raiz)->filho_esq); //chamada recursiva para arvore da esquerda
        (*raiz)->filho_esq = NULL;
        (*raiz)->filho_dir = NULL;

        free(*raiz); //libera a memoria
        *raiz = NULL;
    }
}

void ab_apagar_arvore(AB **T) {
    apaga_nos(&(*T)->raiz);
    free(*T);
    *T = NULL;
}
 
 
int ab_estritamente_binaria (AB *T){ 
    if (T->estritamenteBinaria > 0) return 1; //não é estritamente binaria

    return 0;
}
