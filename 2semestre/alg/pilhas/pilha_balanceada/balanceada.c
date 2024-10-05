#include "item.h"
#include "Pilha.h"

bool balanceada(char *sequencia) {
    PILHA *p = pilha_criar(); ITEM *item, *temp; 
        
    for (int i = 0; sequencia[i] != '\0'; i++) {

        item = item_criar(0, &sequencia[i]);

        if (sequencia[i] == '(' || sequencia[i] == '{' || sequencia[i] == '[') {
            pilha_empilhar(p, item);
        }
        else {
            if (pilha_vazia(p)) {
                pilha_apagar(&p);
                item_apagar(&item);
                return false;}

            item = pilha_topo(p); //vazamento de mem :(
            char topo_char = *(char *)item_get_dados(item);
          

            if ((sequencia[i] == ')' && topo_char == '(') || 
                (sequencia[i]  == '}' && topo_char == '{') || 
                (sequencia[i]  == ']' && topo_char == '[')) {

                pilha_desempilhar(p);

            }
            else{
                pilha_apagar(&p);
                item_apagar(&item);
                return false;
            } 
        }
    }

    bool result = pilha_vazia(p);
    pilha_apagar(&p); 
    item_apagar(&item);
    return result;
    }