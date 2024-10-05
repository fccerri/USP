#include <stdio.h>

void entrada (float mat[100][25], int *n, int *m);
void operacao(float mat[100][25], float notas[100], float media[25], int n, int m);
void bubble(float vet[25], int n);
void swap(float *p1, float *p2);
void saida(float vet[25], int n);

int main (void) {
    int n, m; float mat[100][25], notas[100], media[25];

    entrada(mat, &n, &m);

    operacao(mat, notas, media, n , m);

    bubble(media , m);

    saida(media, m);

    return 0;
}

void entrada (float mat[100][25], int *n, int *m) {
    scanf("%d%d", n, m);
    for (int i = 0; i<*n; i++) {
        for (int j = 0; j<*m; j++) {
            scanf(" %f", &mat[i][j]);
        }
    }
}

void operacao(float mat[100][25], float notas[100], float media[25], int n, int m) {
    for (int i = 0; i<m; i++) {
        media[i] = 0;
    }
    for (int i =0; i<n; i++) {
        notas[i] = 0;
        for (int j = 0; j<m; j++) {
            notas[i] += mat[i][j];
            media [j] += mat[i][j];
        }
        notas[i] /= m;
        printf("Media do aluno %i = %.2f : ", i+1, notas[i]);
        if (notas[i] >= 5) printf("Aprovado\n");
        else printf("Reprovado\n");
    }
    printf("\n");
    for (int i = 0; i<m; i++) {
        media[i] /= n;
    }
}

void saida(float vet[25], int n) {
    for (int i =0; i<n; i++) {
        printf("%.2f ", vet[i]);
    }
}

void bubble(float vet[25], int n) {
    int swaps=1;
    while (swaps !=0) {
        swaps = 0;
        for (int i=0; i<=n-1; i++) {
            if (vet[i] < vet[i+1]) {
                swap(&vet[i], &vet[i+1]);
                swaps++;
            }
        }

    }
}

void swap(float *p1, float *p2){
    float temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
