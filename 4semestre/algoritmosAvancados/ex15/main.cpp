#include <bits/stdc++.h>

using namespace std;

#define INDEF 0
#define VITORIA 1
#define DERROTA 2

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, s; cin >> n >> m >> s;
            
        vector<vector<int>> adj_rev(n); //lista de adjacencias reversa
        vector<int> grau_saida(n, 0); 
            
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj_rev[v].push_back(u); //insere na lista reversa
            grau_saida[u]++;
        }
    
        vector<int> estado(n, INDEF);// armazena o estado de cada nó
        queue<int> fila;
    
        for (int i = 0; i < n; ++i) { //identifica nós sem saida
            if (grau_saida[i] == 0) {
                estado[i] = DERROTA;
                fila.push(i);
            }
        }
    
        //propaga os estadso
        while (!fila.empty()) {
            int v = fila.front(); // v já está com o estado final
            fila.pop();
        
            int estado_v = estado[v];
        
            // percorre todas as fontes de u para v
            for (int u : adj_rev[v]) {
                if (estado[u] != INDEF) continue; // já resolvido -> ignora
            
                if (estado_v == DERROTA) { //ir de u pra v é uma derrota
                    estado[u] = VITORIA; //quem está em u ganha
                    fila.push(u);
                }
                else if (estado_v == VITORIA) { //estado de derrota em u
                    grau_saida[u]--; //elina a opção
                
                    //se todas as opções u->v ja foram checadas -> derrota
                    if (grau_saida[u] == 0) {
                        estado[u] = DERROTA;
                        fila.push(u);
                    }
                }
            }
        }
    
        //define o vencedor
        if (estado[s] == VITORIA)
            cout << "Ash" << endl;
        else 
            cout << "Noir" << endl;
    }
}