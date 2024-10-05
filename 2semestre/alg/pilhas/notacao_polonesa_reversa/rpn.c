#include "item.h"
#include "Pilha.h"
#include <stdlib.h>

float rpn(char *sequencia) {
    ITEM *aux; 
    PILHA *p = pilha_criar();
    float result = 0, temp1, temp2;

    for (int i = 0; i < 100 && sequencia[i] != '\0'; i++) {
        
        if (sequencia[i] >= '0' && sequencia[i] <= '9') {
            float f = sequencia[i] - '0';
            float *pf = malloc(sizeof(float));
            *pf = f;

            ITEM *item = item_criar(0, pf);
            pilha_empilhar(p, item);
            continue;   
        }

        aux = pilha_desempilhar(p); 
        temp1 = *(float*)item_get_dados(aux);
        item_apagar(&aux);
        
        aux = pilha_desempilhar(p);
        temp2 = *(float*)item_get_dados(aux);
        item_apagar(&aux);
        

        switch (sequencia[i]) {
            case '-': result = temp2 - temp1; break;
            case '+': result = temp2 + temp1; break;
            case '/': result = temp2 / temp1; break;
            case '*': result = temp2 * temp1; break;
        }

        float *presult = malloc(sizeof(float));
        *presult = result;
        ITEM *item = item_criar(0, presult);
        pilha_empilhar(p, item);
    }

    if (!pilha_vazia(p)) {
        aux = pilha_desempilhar(p);
        result = *(float*)item_get_dados(aux);
        item_apagar(&aux);
    }

    pilha_apagar(&p);

    return result;
}