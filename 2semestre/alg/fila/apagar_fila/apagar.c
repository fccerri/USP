#include "item.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _STRUCTS_

    #define _STRUCTS_

    typedef struct no_ {
        ITEM* item;
        struct no_* proximo;
    }noObj;

    typedef noObj NO;

    typedef struct fila_ {
        NO* inicio;
        NO* fim;
        int tamanho;
    }filaObj;

    typedef filaObj FILA;

#endif

void fila_apagar(FILA **fila) {
    if (fila_vazia(*fila)) { //caso base
        free(*fila); // Libera a memoria da fila
        *fila = NULL;

        return;
    }

    free((*fila)->inicio->item); //apaga o item
    (*fila)->inicio->item = NULL;

    fila_remover(*fila); //remove nó e chama recursao
    fila_apagar(fila); 

    
}
