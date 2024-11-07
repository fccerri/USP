#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ajustaString(char **string);
void removeZero(char **string);
void radixSort(char ***vet, int n);
void countingSort(char ***vet, int n, int digito);

int main () {
    int n; scanf("%*d%d", &n);

    char **vet = malloc(sizeof(char*)*n); //aloca vetor
    for (int i = 0; i<n; i++) {
        vet[i] = calloc(5, sizeof(char)); //aloca numeros
        
        scanf(" %s", vet[i]); //guarda no vetor o valor da string
        ajustaString(&(vet[i]));
        
    }

    radixSort(&vet, n);

    for (int i = 0; i<n; i++) {
        removeZero(&(vet[i]));
        printf("%s ", vet[i]); //printa vetor ordenado
        free(vet[i]); //libera memoria
        vet[i] = NULL;
    }
    free(vet);
    vet = NULL;

    return 0;
}

void radixSort(char ***vet, int n) {
    for (int i = 3; i>= 0; i--) {
        countingSort(vet, n, i);
        for (int j = 0; j<n; j++) {
        }
    }
}

void countingSort(char ***vet, int n, int digito) {
    int count[17] = {0}; // Contador para dígitos de 0 a 16
    int num; //digito relevante de cada numero
    char **output = malloc(n * sizeof(char*)); //vetor que aponta para as strings ja alocadas de vet

    for (int i = 0; i < n; i++) {
        if (digito >= strlen((*vet)[i]) || (*vet)[i][digito] == 0) 
            num = 0; 
        else if ((*vet)[i][digito] >= '0' && (*vet)[i][digito] <= '9')
            num = (*vet)[i][digito] - '0'; // Extrai o dígito relevante
        else 
            num = (*vet)[i][digito] - 'A' + 10; // Extrai o dígito relevante

        count[num]++;
    }

    for (int i = 1; i < 16; i++) {
        count[i] += count[i - 1]; // faz o prefix
    }

    for (int i = n - 1; i >= 0; i--) {
        if (digito >= strlen((*vet)[i]) || (*vet)[i][digito] == 0) 
            num = 0;
        else if ((*vet)[i][digito] >= '0' && (*vet)[i][digito] <= '9')
            num = (*vet)[i][digito] - '0'; // Extrai o dígito relevante
        else 
            num = (*vet)[i][digito] - 'A' + 10; // Extrai o dígito relevante

        output[count[num] - 1] = (*vet)[i]; //determina a ordenacao do digito relevante
        count[num]--; //ajusta o prefix
    }

    for (int i = 0; i < n; i++) { //copia a ordenacao para o vetor 
        (*vet)[i] = output[i];
    }

    free(output);
}

void ajustaString(char **string) {
    int tam = strlen(*string);
    char aux[5];/* strcpy(aux, *string);*/
    memset(aux, '0', 5);
    aux[4-tam] = '\0';
    strcat(aux, *string);
    strcpy(*string, aux);
}

void removeZero(char **string) {
    int i = 0;
    
    while ((*string)[i] == '0') { //acha até onde os zeros vão
        i++;
    }
    //move o onteudo da string para sobrepor os zeros
    memmove(*string, (*string) + i, 5 - i ); 
}
