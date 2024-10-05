#ifndef PILHAD_H
    #define PILHAD_H

    #include "item.h"
    #include <stdbool.h>

    typedef struct pilha_d PILHAD;
    typedef struct no NO;

    PILHAD* pilha_criar(void);
    void pilha_apagar(PILHAD** pilha);
    bool pilha_vazia(PILHAD* pilha);
    bool pilha_cheia(PILHAD* pilha);
    int pilha_tamanho(PILHAD* pilha);
    ITEM* pilha_topo(PILHAD* pilha);
    bool pilha_empilhar(PILHAD* pilha, ITEM* item);
    ITEM* pilha_desempilhar(PILHAD* pilha);
    void pilha_print(PILHAD* p);
    bool balanceada(char *sequencia);

#endif