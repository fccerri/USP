#include <stdio.h>
#include <stdlib.h>


void swap(int *p1, int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void swap_string(char **p1, char **p2){
    char *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

    
void bubble(int *ip, int n, char ***conteudo, int **bytes) {
    int swaps=1;
    while (swaps !=0) {
        swaps = 0;
        for (int i=0; i<=n-1; i++) {
            if (ip[i] < ip[i+1]) {
                swap(&ip[i], &ip[i+1]);
                swap(&((*bytes)[i]), &((*bytes)[i+1]));
                swap_string(&((*conteudo)[i]), &((*conteudo)[i+1]));
                swaps++;
            }
        }
    }
} 


void *aloca_vet(int n, int type) {
    int *vet;
    vet = malloc(n*type);
    return vet;
}

void **aloca_2dimensao(int tam, int typeSize) {
    void **mat;
    mat = malloc(tam*typeSize);
    return mat;
}

void crivo(int **primos) {
    for (int i =0; i<100; i++) {
        (*primos)[i] = 1;
    } 

    for (int i = 2; i*i<=100; i++) {
        if ((*primos)[i] == 0 ) continue;
        for (int j = 2; i*j<=100; j++) {
            (*primos)[j*i] = 0;
        }
    }
}
int soma_primos(int num, int *primos) {
    int soma = 0;
    for (int i = 2; i <= num; i++) {
        if (primos[i]  == 1 && num % i == 0) {
            soma += i; 
            while (num % i == 0) {
                num /= i;  
            }
        }
    }
    return soma;
}


void entrada(int n, int *primos, int **ip, int **bytes, char ***conteudo) {
    *ip = (int*)aloca_vet(n, sizeof(int)); //aloca os vetores
    *bytes = (int*)aloca_vet(n, sizeof(int));
    *conteudo = (char**)aloca_2dimensao(n, sizeof(char*));

    for (int i =0; i<n; i++) {
        scanf("%d", &((*ip)[i])); 
        scanf("%d", &((*bytes)[i]));
        int bytes_real = soma_primos((*bytes)[i], primos); //sera valor real de bytes;
        
        (*conteudo)[i] = (char*)aloca_vet(bytes_real+1, sizeof(char)); //aloca string de acordo com os bytes

        for (int j=0; j<bytes_real; j++) {
            scanf(" %c", &((*conteudo)[i][j]));
        }
        (*conteudo)[i][bytes_real] = '\0';



    }
}

void saida(int n, int *bytes, char **conteudo) {
    for (int i =0; i<n; i++) {
        printf("%s %d\n", conteudo[i], bytes[i]);
    }
}
void libere_mat(char ***mat, int tam) { //libera a memoria 
    for (int i = 0; i<tam; i++) {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
}

int main (void) {
    int n, *ip, *bytes, *primos = aloca_vet(100, sizeof(int)); 
    char **conteudo; 

    crivo(&primos);

    scanf("%d", &n);
    if (n==0) {
        printf("Sem produtos a serem cadastrados");
        return 0;
    }

    entrada(n, primos, &ip, &bytes, &conteudo);

    bubble(ip, n, &conteudo, &bytes);

    saida(n, bytes, conteudo);

    libere_mat(&conteudo, n);
    free(primos); primos = NULL;
    free(ip); ip = NULL;
    free(bytes); bytes = NULL;

    return 0;
}