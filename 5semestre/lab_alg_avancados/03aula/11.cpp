#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> dp(n+1, INT_MAX); dp[0] = 0;
    vector<int> saltos(n);
    for (int i = 0; i < n; i++) cin >> saltos[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) { //percorre os saltos anteriores a i
            if ( j + saltos[j] >= i && dp[j] != INT_MAX) //verifica se a opção j + salto[j] chega na posicao i da dp e se a posição j foi alcançada
                dp[i] = min(dp[i], dp[j] + 1); //minimo entre dp atual e dp de j + 1 salto
        }
    }

    if (dp[n-1] == INT_MAX)
        cout << "Salto impossivel" << endl;
    else
        cout << dp[n-1] << endl;
}