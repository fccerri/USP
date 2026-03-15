#include <bits/stdc++.h>
#include <climits>
using namespace std;



int main () {
    int n, orcamento; cin >> n >> orcamento;
    vector<int> paginas(n);
    vector<int> precos(n);

    for (int i = 0; i < n; i++) cin >> precos[i];
    for (int i = 0; i < n; i++) cin >> paginas[i];

    int max_pag = 0;
    for (int p : paginas) max_pag += p;
    
    //problema: um mesmo livro pode ser usado varias vezes -> tem q inverter aordem dos loops (e percorrer as paginas de tras pra frente)
    vector<int> dp(max_pag+1, INT_MAX);
    for (int i = 0; i < max_pag; i++) { //resolve a dp
        for (int j = 0; j < n; j++) {
            int p = i - paginas[j]; //posicao a ser verificada na dp (= pagina atual - paginas do livro atual)
            if (p >= 0) {
                dp[i] = min(dp[i], dp[p] + precos[j]); //tenta minimizar o custo de obter i paginas
            }
        }
    }

    int max = 0;
    for (int i = 0; i < max_pag; i++) {
        max = dp[i] <= orcamento ? i : max; //pega o maior numero de paginas em que dp[i] < orcamento
    }

    cout << max;
}
