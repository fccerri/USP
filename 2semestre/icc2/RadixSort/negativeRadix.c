#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

void counting_sort(int *vet, int *ordenado, int n, int digito);

int *radix_sort(int *vet, int n);

int get_min(int *vet, int n, int digito);

int get_max(int *vet, int n, int digito);

int potencia_de_10(int potencia);

int main () {
    int n; scanf("%d", &n); 
    int *vet = malloc(sizeof(int)*n);
    for (int i = 0; i<n; i++) scanf("%d", &vet[i]);

    int *temp = radix_sort(vet, n);
    free(vet);
    vet = temp;

    for (int i = 0; i<n; i++) printf("%d ", vet[i]);

    free(vet);
    return 0;
}

void counting_sort(int *vet, int *ordenado, int n, int digito) {
    int min = get_min(vet, n, digito), max = get_max(vet, n, digito), range;

    if (min >= 0) 
        range = max + 1;
    else 
        range = max - min + 1;

    int *prefix = calloc(range, sizeof(int)),   valor, insercao;

    for (int i = 0; i<n; i++) { //determina quantidade de cada valor
        valor = vet[i];
        valor = (valor / potencia_de_10(digito))%10; //somente o digito 
        valor -= min; //corecao
        prefix[valor]++; //insere no vetor auxiliar a quantidade de cada valor
    }

    for (int i = 1; i<=range; i++) { //seta o prefix
        prefix[i] += prefix[i-1];
    }

    for (int i = n -1; i >= 0; i--) {
        valor = vet[i]; //pega id do valor no prefix
        valor = (valor / potencia_de_10(digito))%10; //somente o digito 
        valor -= min; //corecao

        insercao = --prefix[valor]; //determina onde o valor será inserido
        ordenado[insercao] = vet[i]; //insere o valor no vetor ordenado
    }

    for (int i = 0; i<n; i++) { 
        vet[i] = ordenado[i];
    }

    free(prefix);
}

int *radix_sort(int *vet, int n) {
    int *ordenado = malloc(sizeof(int)*n);
    int min = get_min(vet, n, -1),
        max = get_max(vet, n, -1);

    max = max(max,(-1)*min);

    for(int i = 0; max>0; i++) {
        max /= 10; //realiza o counting com base na qtd maxima de digitos
        counting_sort(vet, ordenado, n, i);//ordena valores
    }

    return ordenado;
}



int get_min(int *vet, int n, int digito) {
    int min = 999999, temp;
    if (digito >=0) {
        for (int i =0; i<n; i++) { //obtem o minimo de um digito especifico
            temp = vet[i];
            temp = (temp/potencia_de_10(digito))%10; 

            min = min(min,temp);
        }
    }
    else { //obtem o mínimo total
        for (int i =0; i<n; i++) {
            temp = vet[i];
            min = min(min,temp);
        }
    }
    return min;
}

int get_max(int *vet, int n, int digito) {
    int max = -999999, temp;
    if (digito >=0) { //obtem o maximo de um digito especifico
        for (int i =0; i<n; i++) {
            temp = vet[i];
            temp = (temp/potencia_de_10(digito))%10; 
            
            max = max(max,temp);
        }
    }
    else { //obtem o maximo total
        for (int i =0; i<n; i++) {
            temp = vet[i];
            max = max(max,temp);
        }
    }
    return max;
}

int potencia_de_10(int potencia) { 
    int pot = 1;
    for (int i =0; i<potencia; i++) 
        pot *= 10;

    return pot;
}