#include <bits/stdc++.h>
using namespace std;



int main () {
    int n, orcamento; cin >> n >> orcamento;
    vector<int> paginas(n);
    vector<int> precos(n);

    for (int i = 0; i < n; i++) cin >> precos[i];
    for (int i = 0; i < n; i++) cin >> paginas[i];

    int max_pag = 0;
    for (int p : paginas) max_pag += p;
    
    vector<int> dp(max_pag+1, INT_MAX); dp[0] = 0; //dp[i] é o valor minimo para obter i paginas
    for (int j = 0; j < n; j++) {
    for (int i = max_pag; i >= paginas[j]; i--) { //percorrer de tras pra frente garante que livros nao sejam repetidos
        int p = i - paginas[j]; //pagina retirando livro atual
        if (dp[p] != INT_MAX)
            dp[i] = min(dp[i], dp[p] + precos[j]);
    }
}

    int max = 0;
    for (int i = 0; i <= max_pag; i++) {
        max = dp[i] <= orcamento ? i : max; //pega o maior numero de paginas em que dp[i] < orcamento
    }

    cout << max << endl;
}
