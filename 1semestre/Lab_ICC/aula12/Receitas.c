#include <stdio.h>
#include <stdlib.h>

typedef struct estoque{
    int farinha, ovos, oleo, acucar, chocolate;

}Estoque;

typedef struct receita {
    char nome[21];
    int farinha, ovos, oleo, acucar, chocolate;

}Receita ;

void recebe(Estoque *Deposito) {
    int farinha, ovos, oleo, acucar,chocolate;
    scanf("%d %d %d %d %d", &farinha, &ovos,
    &oleo, &acucar, &chocolate);
    (*Deposito).farinha += farinha;
    (*Deposito).ovos += ovos;
    (*Deposito).oleo += oleo;
    (*Deposito).acucar += acucar;
    (*Deposito).chocolate += chocolate;

}

void cadastro(int *Qtd, Receita  **Pcaderno) {
    int i = *Qtd;
    (*Qtd)++;
    *Pcaderno = realloc(*Pcaderno, ((*Qtd)+1)*sizeof(Receita));
    scanf(" %s", (*Pcaderno)[i].nome);
    scanf("%d%d%d%d%d", &(*Pcaderno)[i].farinha, &(*Pcaderno)[i].ovos,
    &(*Pcaderno)[i].oleo, &(*Pcaderno)[i].acucar, &(*Pcaderno)[i].chocolate);

}

void cozinha(Estoque *Deposito, Receita *Caderno, int i){
    int count=0;
    if ((*Deposito).farinha < Caderno[i].farinha) {
        printf("Farinha insuficiente\n");
        count++;
    }
    else if ((*Deposito).ovos < Caderno[i].ovos) {
        printf("Ovos insuficientes\n");
        count++;
    }
    else if ((*Deposito).oleo < Caderno[i].oleo) {
        printf("Oleo insuficiente\n");
        count++;
    }
    else if ((*Deposito).acucar < Caderno[i].acucar) {
        printf("Acucar insuficiente\n");
        count++;
    }
    
    else if ((*Deposito).chocolate < Caderno[i].chocolate) {
        printf("Chocolate insuficiente\n");
        count++;
    }
    if (count == 0) {
    (*Deposito).farinha -= Caderno[i].farinha;
    (*Deposito).ovos -= Caderno[i].ovos;
    (*Deposito).acucar -= Caderno[i].acucar;
    (*Deposito).oleo -= Caderno[i].oleo;
    (*Deposito).chocolate -= Caderno[i].chocolate;
    printf("%s feita com sucesso!\n", Caderno[i].nome);
    }


 }




int main (void) {
    char comando; Estoque Deposito; int Qtd = 0, id; Receita *Caderno;
    Caderno = (Receita*)malloc(sizeof(Receita)*2);

    do {
        scanf(" %c", &comando);
        switch (comando) {
            case 'R': {
                cadastro(&Qtd, &Caderno);
                break;  
            }
            case 'C': {
                recebe(&Deposito);
                break;

            }
            case 'F': {
                scanf("%d", &id);
                if (id+1>Qtd){
                    printf("Receita nao encontrada!\n");
                }
                else { cozinha(&Deposito, Caderno, id); }

                break;

            }
            case 'S':break;
            default: printf("Codigo invalido\n");
        }
    }while(comando != 'S');

    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", Deposito.acucar);
    printf("Chocolate: %d\n", Deposito.chocolate);
    printf("Farinha: %d\n", Deposito.farinha);
    printf("Oleo: %d\n", Deposito.oleo);
    printf("Ovos: %d\n", Deposito.ovos);
    printf("Receitas cadastradas: %d\n", Qtd);

   return 0;

}