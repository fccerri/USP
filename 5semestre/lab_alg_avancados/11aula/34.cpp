#include <bits/stdc++.h>
#include <climits>

using namespace std;


int bfs(int s, int t, vector<int> &caminho, vector<vector<int>> &capacidade, vector<vector<int>> &adj) {
    fill(caminho.begin(), caminho.end(), -1); //marca como nao visitado
    caminho[s] = -2; //adiciona flag de parada
    queue<pair<int, int>> q; //fia (no atual,fluxo)
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int atual= q.front().first;
        int fluxo = q.front().second;
        q.pop();

        for (auto prox : adj[atual]) {
            if (caminho[prox] == -1 && capacidade[atual][prox] > 0) { //garante que nao chegou ao fim
                caminho[prox] = atual;
                int fluxo_novo = min(fluxo, capacidade[atual][prox]); //verifica residup
                if (prox == t) //verifica fim
                    return fluxo_novo;
                q.push({prox, fluxo_novo});
            }
        }
    }

    return 0;
}

int ford(int s, int t, vector<vector<int>> &capacidade, vector<vector<int>> &adj, int n) {
    int fluxo = 0;
    vector<int> caminho(n);
    int novo_fluxo = 0;

   while (true) {
        novo_fluxo = bfs(s, t, caminho, capacidade, adj);
        if (novo_fluxo == 0) break; //para se nao ha como melhorar
        
        fluxo += novo_fluxo;
        int atual = t;
        while (atual != s) {
            int anterior = caminho[atual];
            capacidade[anterior][atual] -= novo_fluxo; //atualiza fluxo reverso 
            capacidade[atual][anterior] += novo_fluxo; //atualiza fluxo
            atual = anterior;
        }
   }

    return fluxo;
}


int main () {
    int nodes, edges, s, t; cin >> nodes >> edges >> s >> t;
    
    vector<vector<int>> capacidade(nodes + 1, vector<int>(nodes + 1, 0));
    vector<vector<int>> adj(nodes + 1);
    
    for (int i = 0; i < edges; i++) {
        int u, v, c; cin >> u >> v >> c;
        capacidade[u][v] += c; 
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    
    cout << ford(s, t, capacidade, adj, nodes + 1);
    
    return 0;
}