#include "pilhaD.h"
#include "item.h"
#include <stdbool.h>
#include <stdlib.h>

    struct no {
        ITEM *item;
        NO *anterior;
    };

    struct pilha_d {
        int tam;
        NO *topo;
    };

    PILHAD* pilha_criar(void) {
        PILHAD *p = malloc(sizeof(PILHAD*));

        if (p ==NULL) 
            exit(1);

        p->tam = 0;
        p->topo = NULL;

        return p;
    }

    void pilha_apagar(PILHAD** pilha){
        if (pilha == NULL)
            exit(1);
        NO *aux;
        for (int i = 0, n = pilha_tamanho(*pilha); i <n ; i++) {
            aux = (**pilha).topo;
            item_apagar(&aux->item); //apaga o item do no do topo
            (*pilha)->topo = (*pilha)->topo->anterior;
            aux->anterior = NULL; //dereferencia o ponteiro do no do topo
            free(aux);
            aux = NULL;
        }
        free(*pilha);
        *pilha = NULL;
    }
    bool pilha_vazia(PILHAD* pilha) {
        if (pilha != NULL && pilha->tam != 0) return true;
        return false;

    }
    
    bool pilha_cheia(PILHAD* pilha); //nem precisa

    int pilha_tamanho(PILHAD* pilha) {
        if (pilha != NULL) return pilha->tam;
        return 0;
    }

    ITEM* pilha_topo(PILHAD* pilha) {
        if (pilha == NULL) return NULL;
        return pilha->topo->item;
    }
    bool pilha_empilhar(PILHAD* pilha, ITEM* item) {
        NO *n = malloc(sizeof(NO*));

        if (n != NULL || pilha_cheia(pilha)){
            n->anterior = pilha->topo; //seta ponteiro pro no anterior
            n->item = item; //seta o dado do novo no
            pilha->topo = n; //seta o ponteiro do topo pro novo no 
            pilha->tam++;
            return true;
        }
        return false;
    }
    ITEM* pilha_desempilhar(PILHAD* pilha) {
        if (pilha_cheia(pilha) || pilha->topo ==NULL)
            return NULL;
        NO *no; ITEM *i;
        no = pilha->topo;
        i = pilha->topo->item;
        pilha->topo = pilha->topo->anterior;

        // item_apagar(&no->item); não precisa apagar???
         no->anterior = NULL;
        free(no); no = NULL; 

        pilha->tam--;
        return i;
    }
    void pilha_print(PILHAD* p) {

    }

    