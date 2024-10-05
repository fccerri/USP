#include <stdio.h>

void swap (int *p1, int *p2);
void bubble(int *pv, int tam);
void fib(int vet[50], int tam);

int main (void) {
    int n = 0, vet[50], tam = 0, res[100];
    char comando;

    while (n!=1) { //recebe os valores do vetor incluindo o 1 
        scanf("%d", &n);
        vet[tam] = n;
        tam++;
    }
    tam--;
    
    scanf(" %c", &comando);
    // a = ordena 
    // b = fibb
    // c = case letters
    switch (comando) {
        case 'a': {
            int *pv = vet;
            bubble(pv, tam); //ordena o vetor
            printf("vetor ordenado:");
            for ( int i =0; i<tam; i++ ) { //impreime o vetor ordenado
                printf ("%d ", vet[i]);
            }
            return 0;
        }
        case 'b' : {
            fib(vet, tam); //ja faz tudo 
            return 0;
        }
        case 'c' : {
            printf("Vetor maiusculo:");
            for (int i =0; i<tam; i++) { //imprime o vetor com a correção da leta maiscula 
                printf("%c ", vet[i]-32);
            }
            return 0;
        }
        default: {
            printf("Comando inexistente");
            return 0;
        }
    }

}
void fib(int vet[50], int tam) {
    printf("Numeros de Fibonacci:");
    int n1 = 1, n2 = 1, fib[15], i=0;
    while (n2<2000) { //calcula e joga fibonacci em um vetor até os 2000
        n2 = n1 + n2;
        n1 = n2 - n1;
        fib[i] = n2;
        i++;
    }
    for (int i = 0; i<tam; i++) { //imprime os numeros de fib q aprecem no vetor dado 
        for (int j = 0; j < 15; j++) {
            if (fib[j] == vet[i]) 
            printf("%d ", fib[j]);
        }
    }
}

void bubble(int *pv, int tam) { //faz um bubble sort no vetor dado
    int swaps = 1;
    while (swaps!=0) { 
        swaps = 0;
        for (int j=0; j<tam-1; j++) {
            if (*(pv +j) > *(pv + j +1)) {
                swap ( pv+j, (pv+j+1));
                swaps++;
            }
        }  
    }
}

void swap (int *p1, int *p2) { //troca duas variaveis
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}