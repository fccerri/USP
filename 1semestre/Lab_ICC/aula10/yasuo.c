/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠤⠀⠒⠒⠂⠐⠒⢢⡦⠆⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠊⠀⠀⠀⠀⠀⠀⠀⠀⠋⢰⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⢑⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢇⠈⠂⠀⠀⠀⠀⠀⠀⠀⢀⠀⡺⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡠⠲⠛⠈⠙⠹⠳⡆⠂⠀⠀⠂⢒⡩⠓⠈⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢰⠁⢀⡀⢀⣤⣄⡀⢈⡗⠒⠬⠙⠧⠴⠋⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣣⣡⡭⠉⠀⡸⡇⡀⠀⣱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⠣⠌⠁⠈⠄⠌⣷⠠⠅⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⢢⡤⡂⡠⠤⣰⡁⡓⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡔⢓⢄⢖⢙⡿⢀⡾⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢰⡫⢑⢥⠖⢣⠗⠁⢠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠰⣤⣮⣥⠤⣼⣷⠖⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠿⠷⢿⠟⠷⣝⢏⣽⡶⠶⠶⠶⠶⠶⠶⠶⢶⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⠑⢠⠣⠦⣽⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢾⢽⢶⣟⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⢾⢼⢺⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠘⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*/
#include <stdio.h>

void entrada (char mat[20][20], int *n, int *m);
void operacao(char mat[20][20], char result[20][20], int n, int m);
int verifier (char result[20][20], int n, int m);
void saida (char result[20][20], int n, int m);

int main (void) {
    int n, m;
    char mat[20][20], result[20][20];

    entrada(mat, &n, &m); 

    operacao(mat, result, n, m);

    if (!verifier(result, n, m)) {
        printf("Eh um dia triste para os mono Yasuo");
        return 0;
    }

    saida(result, n, m);

    return 0;
}

void entrada (char mat[20][20], int *n, int *m) {
    scanf("%d%d", n, m);
    for (int i = 0; i<*n; i++) {
        for (int j = 0; j<*m; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }
}

void operacao(char mat[20][20], char result[20][20], int n, int m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (mat[i][j] == 'c' || mat[i][j] == 'f') 
                result[i][j] = 'x';
            else if (mat[i][j] == 'v') {
                int ver = 0;
                for (int k =0; k<n; k++) {
                    if (mat[k][j] == 'c') {
                    result[i][j] = 'x';
                    ver = 1;
                    break;
                    }
                }

                if (ver == 0 ) {
                    for (int l =0; l<m; l++) {
                        if (mat[i][l] == 'c') {
                        result[i][j] = 'x';
                        ver = 1;
                        break;
                        }
                    }
                }
                if (ver == 0) result[i][j] = 'o';
            }
        }
    }
}
int verifier (char result[20][20], int n, int m) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if (result[i][j] == 'o') { 
                    return 1;
                }
            }
        }
    return 0;

}

void saida (char result[20][20], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j =0; j<m; j++) {
            printf("%c ", result[i][j]);
            if (j == m-1) printf("\n");
        }
    }
}