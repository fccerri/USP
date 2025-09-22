#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#define MAX 999999

using namespace std;

struct heroi {
    double produtividade; //de acordo com o nivel
    double livre; //quando estara livre
    vector<int> questsAtribuidas; //quests
    string nome;


    heroi (string nivel, string nome) {
        this->nome = nome;
        this->livre = 0;
        if (nivel == "Aprendiz") produtividade =  0.75;
        if (nivel == "Aventureiro") produtividade = 1.0;
        if (nivel == "Cavaleiro") produtividade = 1.2;
        if (nivel == "Mestre") produtividade = 1.5;
        if (nivel == "Lenda") produtividade = 2.0;
    }
    heroi () {};



};

struct quest {
    int id;
    int tempo;
    bool concluida; //0 (nao concluida) 
    int rank; //quantas quests existem apontando pra essa
    vector<int> predecessores; //quests que devem ser 
    
    quest(int id, int tempo, string s) {
        this->id = id;
        this-> tempo = tempo;
        concluida = 0;
        this->rank = 0; 
        
        stringstream ss(s);

        int dep;
        
        // le todos os numeros da string
        while (ss >> dep) {
            if (dep != 0) { // ignora o 0 se existi o 0 sir
                predecessores.push_back(dep);
            }
        }
    }
};

struct manager {
    vector<heroi> herois;
    vector<quest> quests;
    double tempoTotal;
    int questsConcluidas;

    manager(): tempoTotal(0) {};

    void setaRank (void) {
        for (auto &q : quests) {
            q.rank = 0; //reinicia rank
            for (auto id : q.predecessores) {
                if (!quests[id-1].concluida) 
                    q.rank++; //se quest nao concluida occore soma ao rank
            }
        }
    }
    
    void insereQuest(quest q) {quests.push_back(q);};
    void insereHeroi(heroi h) {herois.push_back(h);};

    void opera(int m) {//qtd de quests
        while (questsConcluidas < m) {
           vector<int> indicesProntos; //id das quests prontas

            // busca quests prontas
            for (int i = 0; i < quests.size(); i++) {
                quest &q = quests[i];
                if (q.rank == 0 && !q.concluida) {
                    indicesProntos.push_back(i);
                }
            }


            // processaa quests pelos ids
            for (int idx : indicesProntos) {
                quest &q = quests[idx]; 

                double melhorFim = MAX;
                int idHeroiBrabo;
                
                // encontra melhor heroi
                for (int i = 0; i < herois.size(); i++) {
                    double fimAtual = herois[i].livre + (q.tempo / herois[i].produtividade);
                    
                    if (fimAtual < melhorFim) { //goulouso
                        melhorFim = fimAtual;
                        idHeroiBrabo = i;
                    }
                }

                //att heroi
                herois[idHeroiBrabo].livre = melhorFim;
                herois[idHeroiBrabo].questsAtribuidas.push_back(q.id);
                
                // att quest
                q.concluida = true;
                questsConcluidas++;
                
                // att tempo total
                if (melhorFim > tempoTotal) {
                    tempoTotal = melhorFim;
                }
                
            }

            setaRank(); //atualiza os ranks
        
        }
            
    }

    void printa(int n) { 
         for (int i = 0; i < n; i++) { //imprime saida
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

int main () {
    int x; cin >> x;
    while (x--) {
        int niveis[5]; //cada posicao do vetor corresponde a quantos herois possuem o nivel (0 a 4)
        manager g;
        
        int n, m; cin >> n >> m;
        for (int i =0; i< n; i++ ) {
            string nome, nivel; cin >> nome >> nivel;
            heroi h(nivel, nome);
            g.insereHeroi(h);
        }

        for (int i = 0; i < m; i++) {
            int id, tempo; cin >> id >> tempo;
            string dependecias; getline(cin, dependecias);
            quest q(id, tempo, dependecias);
            g.insereQuest(q);
        }
        
        g.opera(m);
        g.printa(n);
    }
}


