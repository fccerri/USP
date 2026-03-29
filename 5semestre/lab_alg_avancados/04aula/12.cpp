#include <bits/stdc++.h>

using namespace std;

const long long int mod = ((long)pow(10,9) + 7);

int main () {
    int n; cin >> n;
    vector<vector<long int>> grid(n+2,vector<long int>(n+2)); //adiciona padding

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '*') 
                grid[i][j] = -1;
            else 
                grid[i][j] = 0;
        }
    }

    if (grid[1][1] == -1 || grid[n][n] == -1) { //obstaculo no inciio -> caminhos impossiveis
        cout << 0; return 0;
    }

    grid[1][1] =  1; //caso base 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == -1) continue; //pula obstaculos   
            if (i == 1 && j == 1) continue; //pula a primeira posicao

            //faz dp acumulando posicoes
            grid[i][j] += (max(grid[i-1][j], (long)0) + max(grid[i][j-1], (long)0))% mod;
        }
    }

    cout << grid[n][n] % mod;
}
