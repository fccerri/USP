#include "item.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 


struct item_ {
    int chave;
    void *comp;
};

ITEM *item_criar(int chave, void *comp) {
    ITEM *i;

    if ((i = malloc(sizeof(ITEM))) ==NULL) {
        exit(1);
    }

    return i;
    }
bool item_apagar(ITEM **item) {
    if (*item != NULL ) {
        free(*item);
        (*item) = NULL;

        return true;
    }

    return false;
}
void item_imprimir(ITEM *item) {
    printf("%d\n", item->chave);
}


int item_get_chave(ITEM *item) {
    return item->chave;
}

bool item_set_chave(ITEM *item, int chave) {
    if (item != NULL) {
        item->chave = chave;
        return true;
    }
    return false;
}

void *item_get_dados (ITEM *item) {
    if (item ==NULL) exit(1);
    return item->comp;
}