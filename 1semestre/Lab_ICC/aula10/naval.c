#include <stdio.h>
#define max 26

void entrada(char mat[max][max], int *n);
void operacao(char mat[max][max]);
void saida (char result[max][max], int n);

int main (void) {
    int n; char mat[26][26];

    entrada(mat, &n);

    operacao(mat);

    saida(mat, n);

    return 0;
}

void entrada (char mat[max][max], int *n) {
    scanf("%d", n);
    for (int i = 0; i<*n; i++) {
        for (int j = 0; j<*n; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }
}

void operacao(char mat[max][max]) {
    int n, j_cord; char i_cord;
    scanf("%d", &n);

    for (int k = 0; k<n; k++) {
        scanf(" %c%d", &i_cord, &j_cord);
        i_cord -= 65;
        j_cord--;
        if (mat[i_cord][j_cord] == 'N') {
            printf("acerto!\n");
            mat[i_cord][j_cord] = 'X';
        }
        else {
            printf("erro!\n");
        }

    }
}

void saida (char result[max][max], int n) {
    for (int i=0; i<n; i++) {
        for (int j =0; j<n; j++) {
            printf("%c ", result[i][j]);
            if (j == n-1) printf("\n");
        }
    }
}
