#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct passageiro{
    char Nome[20], Sobrenome[30], CPF[15], Assento[10], Classe[15];
    float Valor;
    short int Status; //cancelado(1) ou ativo(0)
}Passageiro;

typedef struct voo{
    char Status; //aberto(0) ou fechado(1)
    int QtdAssentos;
    float ValorEconomica;
    float ValorExecutiva;
    int AssentosOcupados;
    char Voo[15], Origem[5], Destino[5]; 
    int Dia, Mes, Ano;
    int Canceladas; 

}Voo;


void CopiaDados(Passageiro **Reserva, Voo *InfVoo, int *TamVet);

void GuardaDados(Passageiro *Reserva, Voo InfVoo);

void FechamentoVoo(Passageiro *Reserva, Voo *InfVoo);

void ModificarReserva(Passageiro *Reserva, Voo *InfVoo);

void ImprimirReserva(Passageiro Reserva, Voo InfVoo);

int AchaReserva(Passageiro *Reserva);

void FechamentoDia(Passageiro *Reserva, Voo InfVoo);

void RealocaVet(Passageiro **Reserva, int Ocupado, int *Alocado);

void RealizarReserva(Passageiro **Reserva, int *PassageirosAlocados, Voo *InfVoo);



int main (void) {

    int PassageirosAlocados; char Comando[5];
    Passageiro *Reserva = NULL;
    Voo InfVoo; 

    CopiaDados(&Reserva, &InfVoo, &PassageirosAlocados);

    while(1) {
        scanf(" %2s", Comando);

        


        if (!strcmp(Comando, "FV") || InfVoo.QtdAssentos == InfVoo.AssentosOcupados-InfVoo.Canceladas){
            FechamentoVoo(Reserva, &InfVoo); //imprime informacaoes
            GuardaDados(Reserva, InfVoo);
        
        }
        else if (!strcmp(Comando, "RR")) { //precisa de variavel que guarda asReservas no dia
            RealocaVet(&Reserva, InfVoo.AssentosOcupados, &PassageirosAlocados);

            RealizarReserva(&Reserva, &PassageirosAlocados, &InfVoo);

        }
        else if (!strcmp(Comando, "CR")) { //Consultar Reserva

            int i=AchaReserva(Reserva);     //a função AchaReserva retorna o indice do struct correspondente ao cpf que ela ler
            if(Reserva[i].Status)
                printf("Reserva não encontrada.\n");
            else
                ImprimirReserva(Reserva[i], InfVoo);  
           
        }
        else if (!strcmp(Comando, "MR")) { //Modificar Reserva
            ModificarReserva(Reserva, &InfVoo);
            
        
        }
        else if (!strcmp(Comando, "CA")) { 
            if (InfVoo.Status == 1){
                FechamentoVoo(Reserva, &InfVoo);
            }
            else{
                Reserva[AchaReserva(Reserva)].Status = 1;
                InfVoo.Canceladas++;
            }
            
        }
        else if (!strcmp(Comando, "FD")) {
            //funcao que imprime informacoes;
            GuardaDados(Reserva, InfVoo);
            FechamentoDia(Reserva, InfVoo);
            free(Reserva);
            Reserva = NULL;
            return 0;
        }
        
    }
    
    return 0;
}



void CopiaDados(Passageiro **Reserva, Voo *InfVoo, int *PassageirosAlocados) {
    FILE* fp = fopen("Dados.bin", "rb");
    char Comando[5]; 
    if (fp != NULL) { //o arquivo existe 
        fread(InfVoo, sizeof(Voo), 1, fp);
        //(*Reserva) = (Passageiro*)Aloca((InfVoo->AssentosOcupados)+10, sizeof(Passageiro)); //aloca oq ja tinha +10
        (*Reserva) = (Passageiro*) malloc(sizeof(Passageiro)*(InfVoo->AssentosOcupados)); 
        fread(&(*Reserva), sizeof(Passageiro), InfVoo->AssentosOcupados, fp);
        *PassageirosAlocados = InfVoo->AssentosOcupados;
        fclose(fp);
    } 
    else { //o arquivo nao existe 
        
        (*Reserva) = (Passageiro*) malloc(sizeof(Passageiro)*10); //se n tem aloca 10
        *PassageirosAlocados = 10;
        
        
        scanf(" %s", Comando);
        scanf(" %d %f %f", &(InfVoo->QtdAssentos), &(InfVoo->ValorEconomica), &(InfVoo->ValorExecutiva));
        InfVoo->Canceladas = 0; 
        InfVoo->AssentosOcupados = 0; 
        InfVoo->Status = 0; 


    }

    
}

void RealizarReserva(Passageiro **Reserva, int *PassageirosAlocados, Voo *InfVoo) { //InfVoo guarda info sobre o voo 
    if(InfVoo->Status == 1){ //o voo está fechado 
        FechamentoVoo((*Reserva), InfVoo); 
    }else{
        int i =  InfVoo->AssentosOcupados;  
        scanf(" %s %s %s %d %d %d %s %s %s %f %s %s", (*Reserva)[i].Nome,  (*Reserva)[i].Sobrenome,  (*Reserva)[i].CPF, 
        &InfVoo->Dia, &InfVoo->Mes, &InfVoo->Ano, InfVoo[i].Voo, (*Reserva)[i].Assento, (*Reserva)[i].Classe,
        &(*Reserva)[i].Valor, InfVoo->Origem, InfVoo->Destino);  
        (*Reserva)[i].Status = 0;
        InfVoo->AssentosOcupados++; 
    }
    
}

void ImprimirReserva(Passageiro Reserva, Voo InfVoo) { 
    printf("%s\n", Reserva.CPF);
    printf("%s %s\n", Reserva.Nome, Reserva.Sobrenome);
    printf("%02d/%02d/%d\n", InfVoo.Dia, InfVoo.Mes, InfVoo.Ano);
    printf("Voo: %s\n", InfVoo.Voo);
    printf("Assento: %s\n", Reserva.Assento);
    printf("Classe: %s\n", Reserva.Classe);
    printf("Trecho: %s %s\n", InfVoo.Origem, InfVoo.Destino);
    printf("Valor: %.2f\n", Reserva.Valor);
    printf("--------------------------------------------------\n");
}

int AchaReserva(Passageiro *Reserva) {
    char Consulta[15]; int i = 0;
    scanf(" %s", Consulta);

    while (strcmp(Consulta, Reserva[i].CPF)!= 0) {
        i++;
    }
    return i;
}

void ModificarReserva(Passageiro *Reserva, Voo *InfVoo) {
    if(InfVoo->Status == 1){ //o voo está fechado 
        FechamentoVoo(Reserva, InfVoo);
        return;
    }
    int i=AchaReserva(Reserva);
    if(Reserva[i].Status){
        printf("Reserva não encontrada.\n");
        return;
    }
        scanf(" %s", Reserva[i].Nome);
        scanf(" %s", Reserva[i].Sobrenome);
        scanf(" %s", Reserva[i].CPF);
        scanf(" %s", Reserva[i].Assento);

        printf("Reserva Modificada:\n");

        ImprimirReserva(Reserva[i], (*InfVoo));
}

void FechamentoDia(Passageiro *Reserva, Voo InfVoo){
    float ValorParcial=0;

    for(int i=0; i < InfVoo.AssentosOcupados; i++){
        if(Reserva[i].Status == 0){
            ValorParcial += Reserva[i].Valor; 
        }
    }
    printf("Fechamento do dia:\nQuantidade de Reservas: %d\nPosição: %.2f\n", InfVoo.AssentosOcupados-InfVoo.Canceladas, ValorParcial);
    printf("--------------------------------------------------\n");
}

void FechamentoVoo(Passageiro *Reserva, Voo *InfVoo) {
    float ValorTotal = 0;
    printf("Voo Fechado!\n");

    for (int i = 0; i < InfVoo->AssentosOcupados; i++) {
        if(Reserva[i].Status)
            continue;
        printf("\n%s\n", Reserva[i].CPF);
        printf("%s %s\n", Reserva[i].Nome, Reserva[i].Sobrenome);
        printf("%s\n", Reserva[i].Assento);
                    
        ValorTotal += Reserva[i].Valor;
    }
    InfVoo->Status = 1; 
    printf("Valor Total: %.2f\n", ValorTotal);
    printf("--------------------------------------------------\n");
    
}

void GuardaDados(Passageiro *Reserva, Voo InfVoo) {
    FILE *fp = fopen("Dados.bin", "wb");
    fwrite(&InfVoo, sizeof(Voo), 1, fp);
    for (int i = 0; i < InfVoo.AssentosOcupados; i++)
    {
        if (Reserva[i].Status == 0) {
        fwrite(&Reserva[i], sizeof(Passageiro), 1, fp);
        }
    }
    
    
    fclose(fp);
}


void RealocaVet(Passageiro **Reserva, int Ocupado, int *Alocado) {
    if (Ocupado == (*Alocado) || (*Alocado) > Ocupado+20) {
        (*Reserva) = (Passageiro*)realloc((*Reserva), (Ocupado+10)*sizeof(Passageiro)); 
        (*Alocado) += 10;
    }
}

/*

Funciona bonitinho se não existe Dados.bin
Quando já existe dá seg fault ou bus error

Linhas 30, 74 e 170 a 188:
Mudei os parametros de MR deixei só o vetor Reserva(Lugares) e InfVoo
Chamei AcharReserva dentro de MR
Arrumei o acesso aos campos de Reserva dentro de MR pq o GPT falou pra por . ao invés de ->
Testei se a reserva achada em MR está cancelada antes de deixar modificar
Printar que a reserva não foi encontrada?

Linhas 69 a 77
CR só imprime os dados se a reserva estiver valida

FD depois de FV? - FD é um comando que nescessariamente precisa ser chamado,
FV pode ter q ser chamado nessa condicao InfVoo.QtdAssentos == InfVoo.AssentosOcupados-InfVoo.Canceladas,
entoa precisa verificar antes de tudo

linha 138 pq int *PassageirosAlocados? - Boa pergunta, acho q nem precisa passar o parametro 

n sei, to revisando oq a natalie fez
vou tentar arrumar a parte do arquivo e rodar valgrind dps
nem, vou compilar, pera ai

vc está fazendo que parte?? tá ja rodou? blz
*/
