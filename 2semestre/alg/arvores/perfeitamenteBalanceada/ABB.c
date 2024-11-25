#include  "ABB.h"
#include "item.h"
#include <asm-generic/errno.h>
#include <stdio.h>
#include <stdlib.h>
#define PerfBal(a, b) (((a) > (b) + 1) || ((b) > (a) + 1) ? 0 : 1)

typedef struct no_ NO;
struct no_ {
    ITEM *item;
    NO *esq_filho;
    NO *dir_filho;
};

struct abb {
    NO *raiz;
};
 
ABB *abb_criar (void) {
    ABB *A = malloc(sizeof(ABB));
    if (A == NULL) exit(ERRO);

    A->raiz = NULL;
    return A;
} 


NO *insere_no(ITEM *item, NO *raiz){
    if (raiz == NULL) { //caso base, insere o novo nó
        NO *aux = calloc(1, sizeof(NO)); //aloca o novo nó
        aux->item = item; //guarda o seu valor
        return aux;
    }
    int valor = item_get_chave(item);
    int valor_raiz = item_get_chave(raiz->item);
        
    if (valor >= valor_raiz) { //caso valor seja MAIOR que a raiz (insercao no lado DIREITO)
        raiz->dir_filho = insere_no(item, raiz->dir_filho); //faz chamada recursiva para o filho direito
    }
    else { //caso valor seja MENOR que a raiz (insercao no lado ESQUERDO)
            raiz->esq_filho = insere_no(item, raiz->esq_filho); //faz chamada recursiva para o filho esquerdo
    }
    return raiz;
}


bool abb_inserir (ABB *T, ITEM *item) {
    if (T == NULL || item == NULL) return 0;

    if (T->raiz == NULL) { // Caso especial: raiz é nula
        T->raiz = calloc(1, sizeof(NO));
        if (T->raiz == NULL) return 0; // Verificar alocação de memória
        T->raiz->item = item;
    }
    else {
        if (insere_no(item, T->raiz) == NULL) return 0;
    }
    
    return 1;
}


void imprime(NO *raiz) {
    if (raiz == NULL) 
        return; //quando o ramo termina

    printf("%d ",  item_get_chave(raiz->item)); //printa o caminho 
    imprime(raiz->esq_filho);
    imprime(raiz->dir_filho);

}

void abb_imprimir (ABB *T) {
    if (T != NULL)
        imprime(T->raiz);
}

void liberaArvore(NO **raiz) {
    if (*raiz != NULL) {
        liberaArvore(&(*raiz)->dir_filho); //chamada recursiva para arvore da direita
        liberaArvore(&(*raiz)->esq_filho); //chamada recursiva para arvore da esquerda
        (*raiz)->esq_filho = NULL;
        (*raiz)->dir_filho = NULL;

        item_apagar(&(*raiz)->item);
        free(*raiz); //libera a memoria
        *raiz = NULL;
    }
}


void abb_apagar (ABB **T) {
    liberaArvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

bool abb_remover(ABB *T, int chave); //falta fzr

ITEM *dfs(NO *raiz, int valor) { //tem q arrumar
    if (raiz == NULL) return NULL; //caso não encontre

    if (item_get_chave(raiz->item) == valor) return raiz->item; //caso o valor tenha sido encontrado

    ITEM *it = dfs(raiz->esq_filho, valor);
    if (item_get_chave(it) == valor) return it; 

    dfs(raiz->dir_filho, valor);
}

ITEM *abb_busca(ABB *T, int chave) {
    return dfs(T->raiz, chave);
}

bool abb_vazia(ABB *T) {
    if (T->raiz == NULL)
        return 1;
    else
        return 0;
}


int calcula_altura(NO *raiz) {
    if (raiz == NULL) return 0;
    int altura_esq = calcula_altura(raiz->esq_filho);
    int altura_dir = calcula_altura(raiz->dir_filho);
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

int calcula_balanceamento(NO *raiz) {
    if (raiz == NULL) return 1; //raiz vazia é balanceada   

    int altura_esq = calcula_altura(raiz->esq_filho);
    int altura_dir = calcula_altura(raiz->dir_filho);

    if (!(PerfBal(altura_esq, altura_dir))) return 0;

    return calcula_balanceamento(raiz->esq_filho) && calcula_balanceamento(raiz->dir_filho);
}

bool abb_perfeitamente_balanceada(ABB *T){ //*Essa função devolve 0 se a Árvore é perfeitamente balanceada e 1 caso contrário*/
    if (T == NULL) return 0;
    return calcula_balanceamento(T->raiz) ? 0 : 1;
}
 
void muda_max_esq(NO *muda, NO *raiz, NO *anterior){
    if(muda->dir_filho != NULL){
        muda_max_esq(muda->dir_filho, raiz, muda);
        return;
    }
    if(raiz == anterior)
        anterior->esq_filho = muda->esq_filho;
    else
        anterior->dir_filho = muda->esq_filho;

    raiz->item = muda->item;
    free(muda); muda = NULL;
}

bool remove_no (NO **raiz, int valor){
    NO *aux;
    if(*raiz == NULL)
        return 0;
    if(valor == item_get_chave((*raiz)->item)){
        if ((*raiz)->esq_filho == NULL|| (*raiz)->dir_filho == NULL) {
            aux = *raiz;

            if((*raiz)->esq_filho == NULL)
                *raiz = (*raiz)->dir_filho;
            else
                *raiz = (*raiz)->esq_filho;

            free(aux);
            aux = NULL;
        }
        else 
            muda_max_esq((*raiz)->esq_filho, (*raiz), (*raiz));

        return 1;
    }
    else
        if(valor < item_get_chave((*raiz)->item))
            return remove_no (&(*raiz)->esq_filho, valor);
        else
            return remove_no (&(*raiz)->dir_filho, valor);
}

bool abb_remover(ABB *T, int chave){
    if (T == NULL)  return 0;
        return (remove_no(&T->raiz, chave));
}
