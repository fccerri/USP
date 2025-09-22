#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 999999

using namespace std;

struct heroi {
    double produtividade;
    double livre;
    vector<int> questsAtribuidas;
    string nome;

    heroi(string nivel, string nome) {
        this->nome = nome;
        this->livre = 0;
        if (nivel == "Aprendiz") produtividade = 0.75;
        else if (nivel == "Aventureiro") produtividade = 1.0;
        else if (nivel == "Cavaleiro") produtividade = 1.2;
        else if (nivel == "Mestre") produtividade = 1.5;
        else if (nivel == "Lenda") produtividade = 2.0;
    }
};

struct quest {
    int id;
    int tempo;
    vector<int> predecessores;
    
    quest(int id, int tempo, string s) {
        this->id = id;
        this->tempo = tempo;
        
        stringstream ss(s);
        int dep;
        while (ss >> dep) {
            if (dep != 0) {
                predecessores.push_back(dep);
            }
        }
    }
};

//topo sort
vector<int> topologicalSort(int quantQuests, vector<quest> &quests) {

    vector<vector<int>> adj(quantQuests + 1); 
    vector<int> entrada(quantQuests + 1, 0);
    
    //constroi grafos de adjacencias
    for (const quest &q : quests) {
        int questIndex = q.id;
        
        for (int depId : q.predecessores) {
            if (depId >= 1 && depId <= quantQuests) {
                adj[depId].push_back(questIndex);
                entrada[questIndex]++;
            }
        }
    }
    
   
    queue<int> q;  //vertices com entrada 0
    for (int i = 1; i <= quantQuests; i++) {
        if (entrada[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int atual = q.front();
        q.pop();
        result.push_back(atual);
        
        for (int vizinho : adj[atual]) {
            entrada[vizinho]--;
            if (entrada[vizinho] == 0) {
                q.push(vizinho);
            }
        }
    }
    
    return result;
}

struct manager {
    vector<heroi> herois;
    vector<quest> quests;
    double tempoTotal;

    manager(): tempoTotal(0) {}

    void insereQuest(quest q) { quests.push_back(q); }
    void insereHeroi(heroi h) { herois.push_back(h); }

    void opera(int m) {
        //faz o topo sort
        vector<int> ordem_topologica = topologicalSort(m, quests);
        
        // armazena tempo de conclusao das quests
        map<int, double> tempoConclusao;
        vector<double> tempoHerois(herois.size(), 0);
        
        // processa em ordem tropocolufa
        for (int idx : ordem_topologica) {
            idx--; //ajusta o id
            quest &q = quests[idx];
            
            double menorTempoTotal = -1;
            int indiceMelhorHeroi = 0;
            
            // calcula o tempo de termino de quest para cada herois
            for (int i = 0; i < herois.size(); i++) {
                double tempoQuest = q.tempo / herois[i].produtividade;
                
                double tempoInicio = tempoHerois[i]; 
                
                // verifica dependencias
                for (int depId : q.predecessores) {
                    if (tempoConclusao.find(depId) != tempoConclusao.end()) {
                        tempoInicio = max(tempoInicio, tempoConclusao[depId]);
                    }
                }
                
                double tempoFim = tempoInicio + tempoQuest;
                
                //escolhe melhor heroi
                if (menorTempoTotal == -1 || tempoFim < menorTempoTotal) {
                    menorTempoTotal = tempoFim;
                    indiceMelhorHeroi = i;
                }
            }
            
            //atribui quest ao melhor heroi
            double tempoQuest = q.tempo / herois[indiceMelhorHeroi].produtividade;
            double tempoInicio = tempoHerois[indiceMelhorHeroi];
            
            // recalcula temp[o de inicio]
            for (int id : q.predecessores) {
                if (tempoConclusao.find(id) != tempoConclusao.end()) {
                    tempoInicio = max(tempoInicio, tempoConclusao[id]);
                }
            }
            
            double tempoFim = tempoInicio + tempoQuest;
            
            //att estruturas
            tempoHerois[indiceMelhorHeroi] = tempoFim;
            tempoConclusao[q.id] = tempoFim;
            herois[indiceMelhorHeroi].questsAtribuidas.push_back(q.id);
            
            //att tempo total 
            if (tempoFim > tempoTotal) {
                tempoTotal = tempoFim;
            }
        }
    }

    void printa(int n) { 
        for (int i = 0; i < n; i++) {
            cout << herois[i].nome << " = {";
            for (int j = 0; j < herois[i].questsAtribuidas.size(); j++) {
                if (j > 0) cout << ",";
                cout << herois[i].questsAtribuidas[j];
            }
            cout << "}" << endl;
        }
        cout << fixed << setprecision(2) << "Tempo mínimo: " << tempoTotal << endl;
    }
};

int main() {
    int x; cin >> x;
    while (x--) {
        manager g;
        int n, m; cin >> n >> m;
        
        for (int i = 0; i < n; i++) {
            string nome, nivel; cin >> nome >> nivel;
            heroi h(nivel, nome);
            g.insereHeroi(h);
        }

        // Limpar buffer
        string temp;
        getline(cin, temp);
        
        for (int i = 0; i < m; i++) {
            int id, tempo; 
            cin >> id >> tempo;
            string dependencias; 
            getline(cin, dependencias);
            quest q(id, tempo, dependencias);
            g.insereQuest(q);
        }
        
        g.opera(m);
        g.printa(n);
        if (x != 0) cout << endl;
    }
    return 0;
}