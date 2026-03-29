#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m; cin >> n >> m;
    vector<vector<long int>> grid(n+2,vector<long int>(m+2, -1)); //adiciona padding

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    
    grid[0][1] = 0; //faz com que o valor seja valido no inicio
    
    for (int i = 1; i <= n; i++) {
        vector<long int> esqDP(m+2, -1); // 1 = dp calculada da esquerda para direita
        vector<long int> dirDP(m+2, -1); // 1 = dp calculada da direita para esquerda

        for (int j = 1; j <= m; j++) { //dp da esquerda pra direita
            long long caminho = max(grid[i-1][j], esqDP[j-1]); // Ajustado: olha para j+1
            if (caminho != -1 && grid[i][j] != -1) { //dp da esquerda pra direita
                esqDP[j] = caminho + grid[i][j];
            }
        }
        for (int j = n; j >= 1; j--) { //dp da direita pra equerda
            long long caminho = max(grid[i-1][j], dirDP[j+1]); // Ajustado: olha para j+1
            if (caminho != -1 && grid[i][j] != -1) { //apenas se viizinhos e posicao nao for barrada
                dirDP[j] = caminho + grid[i][j];
            }
        }

        for (int j = 1; j <= m; j++) { //consolida as duas dps
            grid[i][j] = max(dirDP[j], esqDP[j]);
        }
    }

    cout << grid[n][m] << endl;
}
