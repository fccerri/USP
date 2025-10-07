#include <bits/stdc++.h>

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

    static bool comparaNome(const sistema &a, const sistema &b) { //compara sistemas por nome
        return  a.nome < b.nome;
    }

    static bool comparaX(const sistema &a, const sistema &b) { //compara sistemas por x
        return  a.x < b.x;
    }

    static bool comparaY(const sistema &a, const sistema &b) { //compara sistemas por y
        return  a.y < b.y;
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
                    //garante ordem alfabetica
                    if (sistema::comparaNome(sistemas[i], sistemas[j])) 
                        arestas.push_back({sistemas[i], sistemas[j], dist}); 
                    else 
                        arestas.push_back({sistemas[j], sistemas[i], dist});
                        

                }
                    
            }
        }

        return arestas;
    }
};

struct DSU { //disjoint set uniom
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

    vector<aresta> kruskal(const vector<sistema> &sistemas, double tensaoMaxima) { //algoritmos de resolucao da parte 1
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

struct CPP { //closest pair of points
    vector<sistema> sx, sy; //sistemas odenados por x e por y
    sistema pontoRessonante;
    const double tensaoMaxima;


    CPP (vector<sistema> sistermas, double tensaoMaxima): tensaoMaxima(tensaoMaxima) {
        sx = sistermas;
        sort(sx.begin(), sx.end(), sistema::comparaX);
        sy = sistermas;
        sort(sy.begin(), sy.end(), sistema::comparaY);
    }

    aresta achaPontoRessonante() {
        int inicio = 0; 
        int fim = sx.size() - 1;

        aresta min = achaRecursivo(inicio, fim);

        return min;
    }

    private:
        aresta achaRecursivo(int inicio, int fim) {
            int meio = (inicio + fim) / 2;
            if (inicio - fim <= 3)
                return brutaMinimo(inicio, fim); //faz o brute force

            aresta minEsq = achaRecursivo(inicio, meio);
            aresta minDir = achaRecursivo(meio + 1, fim);
   
            aresta arestaMin =  minEsq.peso < minDir.peso ?  minEsq : minDir; //acha o minmo da direita/esq

            vector<sistema> strip; //contem os pontos em que dsitancia de x á mediana de x < min

            sistema medianaX = sx[meio];
            for (int i = inicio; i < fim; i++) {
                if (sistema::calc_dist(medianaX, sx[i]) < arestaMin.peso)
                    strip.push_back(sx[i]);
            }

            sort(strip.begin(), strip.end(), sistema::comparaY); //precisa utilizar sy pra otimizar

            for (int i = 0; i < strip.size(); i++) {
                //verifica vizinhos da direita
                for (int j = 1; j <= 7 && i+j < strip.size(); i++ ) { //usa a propriedade de que só precisa verificar 7 vizinhos
                    double peso = sistema::calc_dist(strip[i+j], strip[i]);
                    aresta novoMin = aresta(strip[i+j], strip[i], peso);
                    arestaMin = arestaMin.peso < novoMin.peso ? arestaMin : novoMin;
                }
                //verifica vizinhos da esquerda
                for (int j = 1; j <= 7 && i-j > 0; i++ ) { //usa a propriedade de que só precisa verificar 7 vizinhos
                    double peso = sistema::calc_dist(strip[i-j], strip[i]);
                    aresta novoMin = aresta(strip[i-j], strip[i], peso);
                    arestaMin = arestaMin.peso < novoMin.peso ? arestaMin : novoMin;
                }                         
            }
            
            return arestaMin;
        }

        aresta brutaMinimo(int inicio, int fim) {
            double distancia_minima = DBL_MAX;
            aresta aresta_minima;
            aresta_minima.peso = distancia_minima;
                
            //itera pelos sistemas (3 apenas)
            for (int i = inicio; i <= fim; ++i) {
                for (int j = i + 1; j <= fim; ++j) {
                
                    double dist_atual = sistema::calc_dist(sx[i], sx[j]);
                    // se a distancia for a minima ate o momento
                    if (dist_atual < distancia_minima) {
                        distancia_minima = dist_atual; //att distancia minima
                    
                        // cria a nova aresta minimoa, garantindo a ordem alfabetica dos sistemas
                        if (sistema::comparaNome(sx[i], sx[j])) 
                            aresta_minima = aresta(sx[i], sx[j], dist_atual);
                        else 
                            aresta_minima = aresta(sx[j], sx[i], dist_atual);
                    }
                }
            }

            return aresta_minima;
        }

    
};

ostream& operator<<(ostream& os, const aresta& a) { //para printar arestas
    os  << a.s1.nome << ", " << a.s2.nome << ", " << a.peso << fixed << setprecision(2);
    return os;
}

int main () {
    int x; cin >> x;
    for (int i = 0; i < x; i++) {
        int n, importantes; double tensaoMaxima;
        cin >> n >> importantes >> tensaoMaxima;

        vector<sistema> sistemas; //vetor de sistemas

        for (int j = 0; j < importantes; j++ ) { //le os sistemas importantes
            sistema s; cin >> s.nome >> s.x >> s.y;
            sistemas.push_back(s);
        }
    
        DSU d = DSU(sistemas); //inicia o dsu
        vector<aresta> mst = d.kruskal(sistemas, tensaoMaxima); //resolve parte 1

        for (int j = importantes; j <  n; j++ ) { //le o restante dos sistemas
            sistema s; cin >> s.nome >> s.x >> s.y;
            sistemas.push_back(s);
            
        }

        for (auto a : mst) { //printa parte 1
            cout << a << endl;
        }

        CPP c = CPP(sistemas, tensaoMaxima);
        aresta ressonancia = c.achaPontoRessonante();
        cout << "Ponto de ressonância: " << ressonancia << endl; //printa parte 2

        if (i != x- 1) cout << endl;

    }
}