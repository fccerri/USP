#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int x; cin >> x;
    while (x--) {
        
        int n, m; cin >> n >> m;
        vector<vector<long int>> grid(n,vector<long int>(m, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c; cin >> c;
                if (c == 'B') 
                grid[i][j] = 0; //black
                else 
                grid[i][j] = 1; //white
            }
        }

        // acha primeiro B pra altura e maior intervalo entre dois B (lado) 
        int altura = 0, larguraMin = m, larguraMax = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    altura = max(altura, n-i); //seta a altura com base no ponto mais alto
                    larguraMin = min(larguraMin, j); //determina a posicao J do ponto B mais a esquerda
                    larguraMax = max(larguraMax, j); //determina a pos j do ponto B mais a direita  
                }
            }
        }
        
        //a expressao inline avalia se o existe algum ponto de tinta
        cout << altura << " " <<  ((larguraMin > larguraMax) ?  0 : (larguraMax - larguraMin + 1)) << endl;
    }
}
