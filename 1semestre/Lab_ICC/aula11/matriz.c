#include <stdio.h>
#include <stdlib.h>

int sqrtt(int n);
int** aloca_mat(int tam);
void entrada(int *n, int *tam, int ***mat);
void saida(int tam, int **mat);
void libere(int ***mat, int tam);

int main (void) {
    int n, tam, **mat;

    entrada(&n, &tam, &mat);
    
    saida(tam, mat);
    
    libere(&mat, tam);

    return 0;
}
int sqrtt(int n) { //obtem a raiz do numero 
    int count = 0;
    for (int i =0; i*i<n; i++) {
        count ++;
    }
    return count;
}

int** aloca_mat(int tam) { //aloca a matriz
    int **mat;
    mat = (int**)malloc(tam*sizeof(int*)); //aloca o ponteiro para ponteiros
    
    for (int i = 0 ; i<tam; i++) {
        (mat)[i] = (int*)malloc(tam*sizeof(int)); //aloca o ponteiro para inteiros
    }
    return mat;
}

void entrada(int *n, int *tam, int ***mat) { //recebe a entrada
    scanf("%d", n); 
    *tam = sqrtt(*n);
    *mat = aloca_mat(*tam);

    for (int i = 0; i < *tam; i++) { //recebe os valores da matriz
            for (int j = 0; j< *tam; j++) {
                scanf("%d", &((*mat)[i][j]));
            }
        }
        
}

void saida(int tam, int **mat) { //imprime a matriz
    for (int i = 0 ; i < tam; i++) {
        for (int j=0; j<tam; j++) {
            printf("%d ", mat[i][j]);
            if (j == tam-1) printf("\n"); //im
        }
    }
}

void libere(int ***mat, int tam) { //libera a memoria 
    for (int i = 0; i<tam; i++) {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
}