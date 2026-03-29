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
    
    //zera a origem para o padding nao atrapalhar o caso base (grid[1][1])
    grid[1][0] = 0;
    grid[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //faz dp acumulando posicoes
            long long int caminho =  max(grid[i-1][j], grid[i][j-1]); //maximo entre os dois caminhos
            grid[i][j] = caminho == -1 || grid[i][j] == -1 ? -1 : grid[i][j] + caminho; //só coma caminho se atual ou anteriores nao forem bloqueados
        }
    }

    cout << grid[n][m];
}
