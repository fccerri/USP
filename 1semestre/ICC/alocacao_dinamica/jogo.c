#include <stdio.h>
#include <stdlib.h>

void entrada(int n, int m, int **mat);
int** aloca(int n, int m);
void operacao(int n, int m, int **mat);
void libere(int ***mat, int tam);

int main (void) {
    int n, m, **mat;

    scanf("%d%d", &n, &m);
    mat = aloca(n,m);

    entrada(n, m, mat);

    operacao(n, m, mat);

    libere(&mat, n);

    return 0;
}

int** aloca(int n, int m) {
    int **mat;
    mat = (int**)calloc((n+2),sizeof(int*)); //iniciliza a matriz com buffer

    for (int i = 0; i<n+2; i++) {
        (mat)[i] = (int*)calloc(m+2,sizeof(int)); //incializa os vetores(da matriz) com buffer
    }
    return mat;
}

void entrada(int n, int m, int **mat) {
    char analize;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++) {
            scanf(" %c", &analize);
            if (analize == 'X') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}


void operacao(int n , int m, int **mat) {
    int count;
    for (int i = 1; i<n+1; i++){
        for (int j=1; j<m+1; j++) { 
            count = 0;
            if (mat[i][j] == 0) {
                count = mat[i+1][j] + mat[i][j+1] + mat[i-1][j] + mat[i][j-1];

                if (count%2) printf("%c", '.'); //se for impar
                else printf("%c", '*'); //se não for impar
            }
            else printf("%c", 'X');

            if (j == m) printf("\n");    
        }
    }
}  


void libere(int ***mat, int n) { //libera a memoria 
    for (int i = 0; i<n+2; i++) {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
}