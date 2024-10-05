#include "item.h"
#include "Deque.h"
#include <stdlib.h>

struct deque_ {
    int tam;
    int inicio;
    int fim;
    ITEM *item[MAX_TAMANHO+1];
};

DEQUE* deque_criar() {
    DEQUE *dq = malloc(sizeof(DEQUE));
    if (dq == NULL) exit(ERRO);
    dq->tam = 0;
    dq->inicio = 0;
    dq->fim = 1;
    return dq;
}

void deque_apagar(DEQUE** deque) {
    if (!deque_vazia(*deque)) {
        while (!deque_vazia(*deque)) {
            ITEM *it = deque_remover_inicio(*deque);
            item_apagar(&it);
        }
    }
    free(*deque);
    *deque = NULL;
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item) {
    if (deque == NULL || deque_cheia(deque)) return false;
    deque->tam++;
    deque->item[deque->inicio] = item;
    deque->inicio = (MAX_TAMANHO + deque->inicio - 1 ) % MAX_TAMANHO; 
    return true;
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item) {
    if (deque == NULL || deque_cheia(deque)) return false;
    deque->tam++;
    deque->item[deque->fim] = item; 
    deque->fim = (deque->fim + 1) % MAX_TAMANHO;
    return true;
}

ITEM* deque_remover_inicio(DEQUE* deque) {
    if (deque == NULL || deque_vazia(deque)) return NULL;
    deque->tam--;
    deque->inicio = (deque->inicio + 1 ) % MAX_TAMANHO;
    ITEM *temp = deque->item[deque->inicio];
    return temp;
}
ITEM* deque_remover_fim(DEQUE* deque) {
    if (deque == NULL || deque_vazia(deque)) return NULL;
    deque->tam--;
    deque->fim = (MAX_TAMANHO + deque->fim - 1 ) % MAX_TAMANHO; 
    ITEM *temp = deque->item[deque->fim];
    return temp;
}

ITEM* deque_primeiro(DEQUE* deque) {
    if (deque == NULL || deque_vazia(deque)) return NULL; 
    return deque->item[deque->inicio+1];
}

ITEM* deque_ultimo(DEQUE* deque) {
    if (deque == NULL || deque_vazia(deque)) return NULL; 
    return deque->item[deque->fim-1];
}

int deque_contar(DEQUE* deque) {
    if (deque == NULL) exit(ERRO);
    return deque->tam;
}

bool deque_vazia(DEQUE* deque) {
    if (deque != NULL && deque->tam == 0 ) return true;
    return false;
}

bool deque_cheia(DEQUE* deque) {
    if (deque != NULL && deque->tam == MAX_TAMANHO) return true;
    return false;
}