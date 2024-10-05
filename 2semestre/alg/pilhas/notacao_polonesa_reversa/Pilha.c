#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "item.h"

struct pilha {
    ITEM *valor[TAM];
    int tam;
};

PILHA* pilha_criar(void) {
    PILHA *p = malloc(sizeof(PILHA)*TAM);
    if (p != NULL) {
        p->tam = 0;
        return p;
    }
    exit(1);
}
void pilha_apagar(PILHA** pilha) {
    if (*pilha == NULL)
        exit(1);
    
    free(*pilha);
    *pilha = NULL;
}
bool pilha_vazia(PILHA* pilha) {
    if (pilha->tam == 0) {
        return true;
    }
    else if (pilha == NULL)
        exit(1);
    return false;
}
bool pilha_cheia(PILHA* pilha) {
    if (pilha->tam == TAM) {
        return true;
    }
    else if (pilha == NULL)
        exit(1);
    return false;
}
int pilha_tamanho(PILHA* pilha) {
    if (pilha !=NULL)
        exit(1);
    return pilha->tam;
}
ITEM* pilha_topo(PILHA* pilha) {
    if (pilha == NULL)
        exit (1);
    return pilha->valor[pilha->tam - 1];
    
}
bool pilha_empilhar(PILHA* pilha, ITEM* item) {
    if (pilha == NULL)
        exit(1);
    if (pilha->tam == TAM -1)
        return false;
    pilha->valor[pilha->tam-1] = item;
    return true;
}
ITEM* pilha_desempilhar(PILHA* pilha) {
    if (pilha == NULL || pilha_vazia(pilha) == 1)
        exit(1);
    
    ITEM *i = pilha->valor[pilha->tam-1];
    pilha->valor[pilha->tam-1] = NULL;
    pilha->tam--;
    return i;
}
void pilha_print(PILHA* p) {
    for (int i = 0; i< p->tam; i++) {
    printf("%d", item_get_chave(p->valor[i]));
    }
    printf("\n");
}


    