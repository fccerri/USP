#include <stdio.h>

void entrada(double mat[100][100], int *pn, int *pm, double *pp);

int soma(double mat[100][100], double parametro, int n, int m);

void saida(double mat[100][100], int n, int m);

int main (void) {
    int n, m; int *pn = &n, *pm = &m;
    double mat[100][100], parametro; double *pp = &parametro;

    entrada(mat, pn, pm, pp);

    soma(mat, parametro, n, m);

    saida(mat, n, m);


 return 0;
}

void entrada(double mat[100][100], int *pn, int *pm, double *pp) {
    printf ("Insira o tamanho da matriz\n"); scanf("%d%d", pn, pm);
    printf ("Insira o parametro\n"); scanf("%lf", pp);

    printf ("Insira a matriz\n");

    for (int i = 0; i<*pn; i++) {
        for (int j = 0; j<*pm; j++){
            scanf("%lf", &mat[i][j]);
        }
    }
}

int soma(double mat[100][100], double parametro, int n, int m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++){
            if (mat[i][j] > parametro){
                mat[i][j] += parametro;
            }
        }
    }
}


void saida(double mat[100][100], int n, int m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++){
            printf("%.4lf ", mat[i][j]);
        }
        printf("\n");
    }
}
