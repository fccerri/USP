#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;


struct Aresta {
    int dest;          
    int capacidade; 
    int fluxo;
    int idx_reverso; // idx aresta reversa na lista de adjacência do destino
};

struct ford_fulkerson {
    int n; 
    vector<vector<Aresta>> adj;
    vector<bool> visitado;


    ford_fulkerson(int n) : n(n) {
        //ajusta pra facilitar acesso de indice
        adj.resize(n + 1); 
        visitado.resize(n + 1);
    }

    void add_aresta(int u, int v, int capacidade) {
        Aresta direta = {v, capacidade, 0, (int)adj[v].size()};
        Aresta reversa = {u, 0, 0, (int)adj[u].size()};

        adj[u].push_back(direta);
        adj[v].push_back(reversa);
    }

    int dfs(int u, int t, int fluxo_gargalo) {
        // caso base
        if (u == t) return fluxo_gargalo;

        visitado[u] = true; //marca visitado

        for (auto& aresta : adj[u]) {
            int v = aresta.dest;
            int capacidade_residual = aresta.capacidade - aresta.fluxo;

            // vizinho não visitado && capacidade sobrando
            if (!visitado[v] && capacidade_residual > 0) {
                // tante aumentar o fluxo
                int novo_gargalo = min(fluxo_gargalo, capacidade_residual);
                
                int fluxo_enviado = dfs(v, t, novo_gargalo);

                // se o caminho aumentou o fluxo
                if (fluxo_enviado > 0) {
                    // att os fluxos
                    aresta.fluxo += fluxo_enviado;
                    adj[v][aresta.idx_reverso].fluxo -= fluxo_enviado;
                    
                    return fluxo_enviado; // 
                }
            }
        }

        return 0; // não encontrou caminho 
    }

    long long max_velocidade(int s, int t) {
        int fluxo_maximo = 0;
        int fluxo_caminho;

        
        do { //aumenta fluxo enquanto possível
            fill(visitado.begin(), visitado.end(), false); //reseta visitados
            // busca um caminho 
            fluxo_caminho = dfs(s, t, INT_MAX);
            fluxo_maximo += fluxo_caminho;
        } while (fluxo_caminho > 0);

        return fluxo_maximo;
    }

};

int main() {
    int n, m; cin >> n >> m;    
    ford_fulkerson rede(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        rede.add_aresta(u, v, c);
    }

    cout << rede.max_velocidade(1, n) << endl;

    return 0;
}