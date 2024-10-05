#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct passageiro{
    char Nome[20], Sobrenome[20], CPF[15], Assento[10], Classe[15];
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


void CopiaDados(Passageiro **Lugares, Voo *InfVoo, int *TamVet);

void GuardaDados(Passageiro *Lugares, Voo InfVoo);

void FechamentoVoo(Passageiro *Lugares, Voo *InfVoo);

void ModificarReserva(Passageiro *Reserva, Voo *InfVoo, Passageiro *Lugares);

void ImprimirReserva(Passageiro Reserva, Voo InfVoo);

int AchaReserva(Passageiro *Lugares);

void FechamentoDia(Passageiro *Lugares, Voo InfVoo);

void RealocaVet(Passageiro **Lugares, int Ocupado, int *Alocado);

void RealizarReserva(Passageiro **Lugares, int *PassageirosAlocados, Voo *InfVoo);



int main (void) {

    int PassageirosAlocados, ReservasCanceladas = 0; char Comando[5];
    Passageiro *Lugares = NULL;
    Voo InfVoo; 

    CopiaDados(&Lugares, &InfVoo, &PassageirosAlocados);

    while(1) {
        scanf(" %2s", Comando);

        


        if (!strcmp(Comando, "FV") || InfVoo.QtdAssentos == InfVoo.AssentosOcupados-ReservasCanceladas){
            FechamentoVoo(Lugares, &InfVoo); //imprime informacaoes
            GuardaDados(Lugares, InfVoo);
        
        }
        else if (!strcmp(Comando, "RR")) { //precisa de variavel que guarda asReservas no dia
            RealocaVet(&Lugares, InfVoo.AssentosOcupados, &PassageirosAlocados);

            RealizarReserva(&Lugares, &PassageirosAlocados, &InfVoo);

        }
        else if (!strcmp(Comando, "CR")) { //Consultar Reserva
            ImprimirReserva(Lugares[AchaReserva(Lugares)], InfVoo);  //a função AchaReserva retorna o indice do struct correspondente ao cpf que ela ler
           
        }
        else if (!strcmp(Comando, "MR")) { //Modificar Reserva
            ModificarReserva(&Lugares[AchaReserva(Lugares)], &InfVoo, Lugares);
            
        
        }
        else if (!strcmp(Comando, "CA")) { 
            if (InfVoo.Status == 1){
                FechamentoVoo(Lugares, &InfVoo);
            }
            else{
                Lugares[AchaReserva(Lugares)].Status = 1;
            }
            
        }
        else if (!strcmp(Comando, "FD")) {
            //funcao que imprime informacoes;
            GuardaDados(Lugares, InfVoo);
            FechamentoDia(Lugares, InfVoo);
            free(Lugares);
            Lugares = NULL;
            return 0;
        }
        
    }
    
    return 0;
}



void CopiaDados(Passageiro **Lugares, Voo *InfVoo, int *PassageirosAlocados) {
    FILE* fp = fopen("Dados.bin", "rb");
    char Comando[5]; 
    if (fp != NULL) { //o arquivo existe 
        fread(InfVoo, sizeof(Voo), 1, fp); //não sei se ta certo 

        //(*Lugares) = (Passageiro*)Aloca((InfVoo->AssentosOcupados)+10, sizeof(Passageiro)); //aloca oq ja tinha +10
        (*Lugares) = (Passageiro*) malloc(sizeof(Passageiro)*(InfVoo->AssentosOcupados)); 
        fread(&(*Lugares), sizeof(Passageiro), InfVoo->AssentosOcupados, fp);
        *PassageirosAlocados = InfVoo->AssentosOcupados;
        fclose(fp);
    } 
    else { //o arquivo nao existe 
        
        (*Lugares) = (Passageiro*) malloc(sizeof(Passageiro)*10); //se n tem aloca 10
        *PassageirosAlocados = 10;
        
        
        
        scanf(" %s", Comando);
        scanf(" %d %f %f", &(InfVoo->QtdAssentos), &(InfVoo->ValorEconomica), &(InfVoo->ValorExecutiva));
        InfVoo->Canceladas = 0; 
        InfVoo->AssentosOcupados = 0; 
        InfVoo->Status = 0; 


    }

    
}

void RealizarReserva(Passageiro **Lugares, int *PassageirosAlocados, Voo *InfVoo) { //InfVoo guarda info sobre o voo 
    if(InfVoo->Status == 1){ //o voo está fechado 
        FechamentoVoo((*Lugares), InfVoo); 
    }else{
        int i =  InfVoo->AssentosOcupados;  
        scanf(" %s %s %s %d %d %d %s %s %s %f %s %s", (*Lugares)[i].Nome,  (*Lugares)[i].Sobrenome,  (*Lugares)[i].CPF, 
        &InfVoo->Dia, &InfVoo->Mes, &InfVoo->Ano, InfVoo[i].Voo, (*Lugares)[i].Assento, (*Lugares)[i].Classe,
        &(*Lugares)[i].Valor, InfVoo->Origem, InfVoo->Destino);  
        (*Lugares)[i].Status = 0;
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

int AchaReserva(Passageiro *Lugares) {
    char Consulta[15]; int i = 0;
    scanf(" %s", Consulta);

    while (strcmp(Consulta, Lugares[i].CPF)!= 0) {
        i++;
    }
    return i;
}

void ModificarReserva(Passageiro *Reserva, Voo *InfVoo, Passageiro *Lugares) {
    if(InfVoo->Status == 1){ //o voo está fechado 
        FechamentoVoo(Lugares, InfVoo); 
    }
    else{
        scanf(" %s", Reserva->Nome);
        scanf(" %s", Reserva->Sobrenome);
        scanf(" %s", Reserva->CPF);
        scanf(" %s", Reserva->Assento);

        printf("Reserva Modificada:\n");

        ImprimirReserva((*Reserva), (*InfVoo));
    }
}

void FechamentoDia(Passageiro *Lugares, Voo InfVoo){
    float ValorParcial=0;

    for(int i=0; i < InfVoo.AssentosOcupados; i++){
        if(Lugares[i].Status == 0){
            ValorParcial += Lugares[i].Valor; 
        }
    }
    printf("Fechamento do dia:\nQuantidade de Reservas: %d\nPosição: %.2f\n", InfVoo.AssentosOcupados-InfVoo.Canceladas, ValorParcial);
    printf("--------------------------------------------------\n");
}

void FechamentoVoo(Passageiro *Lugares, Voo *InfVoo) {
    float ValorTotal = 0;
    printf("Voo Fechado!\n");

    for (int i = 0; i < InfVoo->AssentosOcupados; i++) {
        printf("\n%s\n", Lugares[i].CPF);
        printf("%s %s\n", Lugares[i].Nome, Lugares[i].Sobrenome);
        printf("%s\n", Lugares[i].Assento);
        
    ValorTotal += Lugares[i].Valor;
    }
    InfVoo->Status = 1; 
    printf("Valor Total: %.2f\n", ValorTotal);
    printf("--------------------------------------------------\n");
    
}

void GuardaDados(Passageiro *Lugares, Voo InfVoo) {
    FILE *fp = fopen("Dados.bin", "wb");
    fwrite(&InfVoo, sizeof(Voo), 1, fp);
    for (int i = 0; i < InfVoo.AssentosOcupados; i++)
    {
        if (Lugares[i].Status == 0) {
        fwrite(&Lugares[i], sizeof(Passageiro), 1, fp);
        }
    }
    
    
    fclose(fp);
}


void RealocaVet(Passageiro **Lugares, int Ocupado, int *Alocado) {
    if (Ocupado == (*Alocado) || (*Alocado) > Ocupado+20) {
        (*Lugares) = (Passageiro*)realloc((*Lugares), (Ocupado+10)*sizeof(Passageiro)); 
        (*Alocado) += 10;
    }
}




/*
Cancelar reserva (segmentation fault)
Guarda dados 
Caso o voo estiver fechado (possivel leitura errada)

*/