#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Deque.h"
#include "item.h"


void set_and_print(DEQUE *dq1);

void exchange_and_print(int n, DEQUE *dq1, DEQUE *dq2);


int main () {
    int n; scanf("%d", &n);
    DEQUE *dq1, *dq2; set_and_print(dq1);
    exchange_and_print(n, dq1, dq2);


}

void exchange_and_print(int n, DEQUE *dq1, DEQUE * dq2){
    printf("\n-------------------\n");
    printf("\nTROCAS\n");
    printf("\n-------------------\n\n"); 

    short int rm, aux; char org[7], dest[7]; ITEM *temp; DEQUE *origem, *destino;

    for (int i =0; i<n; i++) {
        scanf("%hd %s %s", &rm, org, dest);

        if (rm == 1) {
            origem = dq1;
            destino = dq2;
            aux = 1;
        }
        else {
            origem = dq2;
            destino = dq2;
            aux = 2;
        }
        
        if (org[0] == 'i')
            temp = deque_remover_inicio(origem);
        else
            temp = deque_remover_fim(origem);

        if (dest[0] == 'i') 
            deque_inserir_inicio(destino, temp);
        else 
            deque_inserir_fim(destino, temp);

        
        printf("a carta %s\n", (char*)item_get_dados(temp));
        printf("foi removida do deque %hd na posicao %s e inserida no deque %hd na posicao %s\n", rm, org, aux, dest);

    }


}


void set_and_print(DEQUE *dq1) {

    printf("\n-------------------\n");
    printf("\nO BARALHO\n");
    printf("\n-------------------\n");    

    char numero[14][15] = {"Ás", "Dois", "Três", "Quatro", "Cinco",
     "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Rainha", "Rei"},
    naipe[4][7] = {"Paus", "Copas", "Espadas", "Ouros"},
    juncao[4] = {" de "};



    for (int i = 0; i<4; i++) {
        for (int j=0; j<14; j++) {
            char *carta = malloc(sizeof(char)*20);

            strcat(numero[i], juncao);
            strcat(numero[i], naipe[j]);
            strcpy(carta, numero[i]);
            printf("%s\n", carta);

            ITEM *it = item_criar((i*14)+j, carta);
            deque_inserir_inicio(dq1, it);
        }
    }
}
