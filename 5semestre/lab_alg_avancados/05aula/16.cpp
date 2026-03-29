#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    vector<int>a(n+2, 1); //baloes (considerando os imaginarios nas pontas)
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n+2,vector<int>(n+2, 0));

    for (int len = 1; len <= n; len++) { //tam do intervalo
        for (int i = 1; i <= n - len + 1; i++) {  // comeco do intervcalo (i)
            int j = i + len - 1; // fim do intervalo (j)
            //ou seja, intervalo vai de i a j
            //testa todos as ultimas escolhas de baloes possiveis
            for (int k = i; k <= j; k++) {
                int pontos = a[i-1] * a[k] * a[j+1]; //escolhe balao k e pega adjacentes do intervalo
                //pega dp do balao atual + sub intervalos da esquerda  + direita
                dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + pontos);
            }
        }
    }

    cout << dp[1][n] << endl;
}