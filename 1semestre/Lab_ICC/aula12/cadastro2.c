#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char *nome;
    char cpf[12];
    int idade;
    float saldo;
    float divida;
    float credito;
} Pessoa;

void saida(Pessoa *Clientes, int n);
void *AlocaVet(int tam, int Typesize);

int main(void) {
    Pessoa *Clientes;
    int n;

    scanf("%d", &n);
    Clientes = (Pessoa *)AlocaVet(n, sizeof(Pessoa));

    for (int i = 0; i < n; i++) {
        char StrAuxiliar[30];
        scanf(" %29[^,]%*c", StrAuxiliar);
        Clientes[i].nome = (char *)AlocaVet(strlen(StrAuxiliar) + 1, sizeof(char));
        strcpy(Clientes[i].nome, StrAuxiliar);

        scanf(" %11[^,]%*c", Clientes[i].cpf);
        scanf("%d%*c", &Clientes[i].idade);
        scanf("%f%*c", &Clientes[i].saldo);
        scanf("%f%*c", &Clientes[i].credito);

        Clientes[i].divida = Clientes[i].credito - Clientes[i].saldo;
    }

    saida(Clientes, n);

    for (int i = 0; i < n; i++) {
        free(Clientes[i].nome);
    }
    free(Clientes);

    return 0;
}

void saida(Pessoa *Clientes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Dados da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", Clientes[i].nome);
        printf("CPF: %s\n", Clientes[i].cpf);
        printf("Idade: %d\n", Clientes[i].idade);
        printf("Saldo: %.2f\n", Clientes[i].saldo);
        printf("Credito: %.2f\n\n", Clientes[i].credito);
    }

    int count = 0;
    printf("Pessoas endividadas:");
    for (int i = 0; i < n; i++) {
        if (Clientes[i].divida > 0) {
            printf("\nNome: %s\n", Clientes[i].nome);
            printf("CPF: %s\n", Clientes[i].cpf);
            printf("Divida: %.2f\n", Clientes[i].divida);
            count++;
        }
    }
    if (count == 0) {
        printf("\nNenhuma pessoa endividada encontrada.");
    }
}

void *AlocaVet(int tam, int Typesize) {
    void *vet = malloc(tam * Typesize);
    return vet;
}