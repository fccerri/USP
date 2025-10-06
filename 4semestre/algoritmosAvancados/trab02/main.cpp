#include <bits/stdc++.h>
#include <iomanip>

using namespace std;


struct sistema {
    string nome;
    double x;
    double y;

    static double calc_dist(sistema s1, sistema s2) {
        double dx = s1.x - s2.x;
        double dy = s1.y - s2.y;
        
        return sqrt(dx*dx + dy*dy);
    }

    const bool operator <(const sistema &a) const { //compara sistemas por nome
        return nome < a.nome;
    }
    
};


struct aresta {
    sistema s1, s2;
    double peso;

    aresta(sistema s1, sistema s2, double peso) {
        this->s1 = s1; this->s2 = s2; this->peso = peso;  
    }
    aresta() = default; //permite nao inicializar as variaves

    static bool comparaPeso(const aresta &a, const aresta &b){ //para ordenar por peso
        return a.peso < b.peso;
    }

    //assume que s1.nome < s2.nome
    static bool comparaNome(const aresta &a, const aresta &b) { //para ordenar por nome
        if (a.s1.nome < b.s1.nome) {
        return true; // a vem antes de b
        }
        if (a.s1.nome > b.s1.nome) {
            return false; // a vem depois de b
        }

        // se a.s1.nome == b.s1.nome, desempata pelo segundo sistema
        return a.s2.nome < b.s2.nome; //(nao sera necessario para os problemas propostos)
    }

    static vector<aresta> geraArestas(const vector<sistema> &sistemas, double tensaoMaxima) {
        //gera as arestas
        vector<aresta> arestas;
        for (int i = 0; i < sistemas.size(); ++i) {
            for (int j = i + 1; j < sistemas.size(); ++j) {
                double dist = sistema::calc_dist(sistemas[i], sistemas[j]);
                if (dist <= tensaoMaxima) {
                    int s1, s2;
                    if (sistemas[i] < sistemas[j]) { //sistemas ficarão em ordem alfabetica (s1.nome < s2.nome)
                        s1 = i;
                        s2 = j;
                    }
                    else {
                        s1 = j;
                        s2 = i;
                    }

                    arestas.push_back({sistemas[s1], sistemas[s2], dist});
                }
                    
            }
        }

        return arestas;
    }
};

struct DSU {
    map<string, string> pai; //conjuntos
    
    DSU(vector<sistema> sistemas) {
        for (auto s : sistemas) {
            pai[s.nome] = s.nome;
        }
    }

    string find(string id) {
        if (pai[id] == id)
            return pai[id];
        else
            return pai[id] = find(pai[id]); //compressao de caminho (otimizacao) 
    }

    //une os conjuntos de dois sistemas
    void unite(string id1, string id2) {
        string raiz1 = find(id1);
        string raiz2 = find(id2);
        if (raiz1 != raiz2) {
            pai[raiz1] = raiz2;
        }
    }

    vector<aresta> kruskal(const vector<sistema> &sistemas, double tensaoMaxima) {
        vector<aresta> arestas = aresta:: geraArestas(sistemas, tensaoMaxima); //gera arestas do grafo
        sort(arestas.begin(), arestas.end(), aresta::comparaPeso); //ordena por peso 
        
        vector<aresta> mst;

        for (const auto& aresta : arestas) { //percorre arestass ordenadas por peso
            if (find(aresta.s1.nome) != find(aresta.s2.nome)) { //se dois sistemas da aresta nao fazem parte do mesmo conjunto
                unite(aresta.s1.nome, aresta.s2.nome); //une os conjuntos
                mst.push_back(aresta); //adiciona aresta a resposta final
            }
        }

        sort(mst.begin(), mst.end(), aresta::comparaNome); //deixa em ordem alfabetica 
        return mst;
    }

    

};

std::ostream& operator<<(std::ostream& os, const aresta& a) { //para printar arestas
    os  << a.s1.nome << ", " << a.s2.nome << ", " << a.peso << fixed << setprecision(2);
    return os;
}

int main () {
    int x; cin >> x;
    for (int i =0; i < x; i++) {
        int n, importantes; double tensaoMaxima;
        cin >> n >> importantes >> tensaoMaxima;

        vector<sistema> sistemas; //vetor de sistemas
        vector<aresta> mst; //mst (parte 1)
        aresta ressonancia; //ponto de ressonancia

        for (int j = 0; j < importantes; j++ ) { //le os sistemas importantes
            sistema s; cin >> s.nome >> s.x >> s.y;
            sistemas.push_back(s);
        }
    
        DSU d = DSU(sistemas); //inicia o dsu
        mst = d.kruskal(sistemas, tensaoMaxima); //resolve parte 1

        for (int j = importantes; j <  n; j++ ) { //le o restante dos sistemas
            sistema s; cin >> s.nome >> s.x >> s.y;
            sistemas.push_back(s);
            
        }

        for (auto a : mst) { //printa parte 1
            cout << a << endl;
        }

        //resolve parte 2
        // cout << "Ponto de ressonância: " << ressonancia << endl; //printa parte 2
        cout << endl;

    }
}