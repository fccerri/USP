#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct manutencao {
    ll s, f, p;
};

// ordena pelo horario de termino
bool comp(manutencao a, manutencao b) {
    if (a.f == b.f) return a.s < b.s;
    return a.f < b.f;
}

int main () {
    int n; cin >> n;
    
    vector<manutencao> manutencoes(n);
    for (int i = 0; i < n; i++) cin >> manutencoes[i].s >> manutencoes[i].f >> manutencoes[i].p;

    sort(manutencoes.begin(), manutencoes.end(), comp);

    // dp[i] -> {maior_quantidade, maior_soma_prioridades
    // considera manutencaoes de 0 a i
    vector<pair<ll, ll>> dp(n);
    
    ll max_q = 0;
    ll max_p = 0;

    for (int i = 0; i < n; i++) {
        // assume-se que pegamos apenas a manutencao atual
        dp[i] = {1, manutencoes[i].p}; 
        
        // confere compatibilidade
        for (int j = 0; j < i; j++) {
            // Checa se a manutencao j termina antes que o inicio de i
            if (manutencoes[j].f <= manutencoes[i].s) {
                ll cand_qtd = dp[j].first + 1;
                ll cand_prio = dp[j].second + manutencoes[i].p;
                
                // att o estado se necessario
                if (cand_qtd > dp[i].first) {
                    dp[i] = {cand_qtd, cand_prio};
                } 
                // se a quantidade for igual, priorizamos a maior soma de prioridade
                else if (cand_qtd == dp[i].first) {
                    dp[i].second = max(dp[i].second, cand_prio);
                }
            }
        }
        
        // att a resposta global a cada iteracao
        if (dp[i].first > max_q) {
            max_q = dp[i].first;
            max_p = dp[i].second;
        } else if (dp[i].first == max_q) {
            max_p = max(max_p, dp[i].second);
        }
    }
    
    cout << max_q << " " << max_p << endl;

}