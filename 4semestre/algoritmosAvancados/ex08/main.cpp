#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m; 
    cin >> n;
    while (n--) {
        cin >> m;
        vector<int> dominos(m);
        for (int i = 0; i < m; i++) {
            char tmp; int aux1, aux2;
            cin >> tmp >> aux1 >> tmp >> aux2 >> tmp;
            dominos[i] = aux1 + aux2;
        }

        int dp[m][m]; //matriz da dp
        // casos base
        for (int i = 0; i < m; i++)
            dp[i][i] = dominos[i]; //dp é o valor da propria pedra

        for (int tam = 2; tam <= m; tam++) { //tam representa tamnho do intervalo
            //e = indice esquerda, d = indice direita
            for (int e = 0; e + tam - 1 < m; e++) { //itera enquanto direita < m
                int d = e + tam - 1; //indice da direita

                int esq = dominos[e] + min( //caso 1, escolhe a pedra da esquerda
                    (e + 2 <= d ? dp[e + 2][d] : 0), //evita acessar espacos invalidos
                    (e + 1 <= d - 1 ? dp[e + 1][d - 1] : 0)
                );

                int dir = dominos[d] + min( ////caso 2, escolhe a pedra da direita
                    (e <= d - 2 ? dp[e][d - 2] : 0), //evita acessar espacos invalidos
                    (e + 1 <= d - 1 ? dp[e + 1][d - 1] : 0)
                );

                dp[e][d] = max(esq, dir);
            }
        }

        cout << dp[0][m - 1] << endl;

    }
}