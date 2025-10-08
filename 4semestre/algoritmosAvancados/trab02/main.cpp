#include <bits/stdc++.h>

using namespace std;

struct sistema {
    string nome;
    double x;
    double y;
    int id;

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
        this->s1 = s1.id < s2.id ? s1 : s2; //garante que s1.id < s2.id
        this->s2 = s1.id > s2.id ? s1 : s2;  //garante que s2.id > s1.id 
        this->peso = peso;  
    }

    aresta() { //permite nao inicializar as variaves evitando core dumped
        this->s1 = sistema{"", 0.0, 0.0, -1};
        this->s2 = sistema{"", 0.0, 0.0, -1};
        this->peso = DBL_MAX;
    }

    static bool comparaNome(const aresta &a, const aresta &b) { //para ordenar por nome
        if (a.s1.nome < b.s1.nome) {
        return true; // a vem antes de b
        }
        if (a.s1.nome > b.s1.nome) {
            return false; // a vem depois de b
        }

        // se a.s1.nome == b.s1.nome, desempata pelo segundo sistema
        return a.s2.nome < b.s2.nome; 
    }

    static bool comparaID(const aresta &a, const aresta &b) { //compara aresta por id
       if (a.s1.id < b.s1.id) {
        return true; // a vem antes de b
        }
        if (a.s1.id > b.s1.id) {
            return false; // a vem depois de b
        }

        // se a.s1.id == b.s1.id, desempata pelo segundo sistema
        return a.s2.id < b.s2.id; 
    }

    static bool comparaPeso(const aresta &a, const aresta &b){ //para ordenar por peso
        if (a.peso != b.peso) //--- Essas linhas corrigem a saida mal formatada do passo 4
            return a.peso < b.peso;
        else
            return comparaID(a, b); //desempata por ID (ordem de entrada)
    }


    static vector<aresta> geraArestas(const vector<sistema> &sistemas, double tensaoMaxima) {
        //gera as arestas
        vector<aresta> arestas;
        for (int i = 0; i < sistemas.size(); ++i) {
            for (int j = i + 1; j < sistemas.size(); ++j) {
                double dist = sistema::calc_dist(sistemas[i], sistemas[j]);
                if (dist <= tensaoMaxima) {
                    arestas.push_back({sistemas[i], sistemas[j], dist}); 
                }
            }
        }

        return arestas;
    }
};

ostream& operator<<(ostream& os, const aresta& a) { //para printar arestas
    os  << a.s1.nome << ", " << a.s2.nome << ", " << fixed << setprecision(2) << a.peso;
    return os;
}


struct DSU { //disjoint set uniom
    map<string, string> pai; //conjuntos
    
    DSU(vector<sistema> sistemas) { //inicializa
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

    vector<aresta> kruskal(const vector<sistema> &sistemas, double tensaoMaxima) { //algoritmo de resolucao da parte 1
        vector<aresta> arestas = aresta:: geraArestas(sistemas, tensaoMaxima); //gera arestas do grafo
        sort(arestas.begin(), arestas.end(), aresta::comparaPeso); //ordena por peso 
        
        vector<aresta> mst;

        for (const auto& aresta : arestas) { //percorre arestass ordenadas por peso
            if (find(aresta.s1.nome) != find(aresta.s2.nome)) { //se dois sistemas da aresta nao fazem parte do mesmo conjunto
                unite(aresta.s1.nome, aresta.s2.nome); //une os conjuntos
                mst.push_back(aresta); //adiciona aresta a resposta final
            }
        }

        // sort(mst.begin(), mst.end(), aresta::comparaNome); //deixa em ordem de entrada

        return mst;
    }    

};

struct CPP { //closest pair of points
    vector<sistema> sx, sy; //sistemas odenados por x e por y
    const double tensaoMaxima;

    CPP (vector<sistema> sistermas, double tensaoMaxima): tensaoMaxima(tensaoMaxima) { //inicializa 
        sx = sistermas;
        sort(sx.begin(), sx.end(), sistema::comparaX);
        sy = sistermas;
        sort(sy.begin(), sy.end(), sistema::comparaY);
    }

    aresta achaPontoRessonante() { //algoritmo para resolucao da parte 2
        int inicio = 0; 
        int fim = sx.size() - 1;

        aresta min = achaRecursivo(inicio, fim, sy);

        return min;
    }

    private:
        aresta setArestaMin(aresta a, aresta b) { //compara duas aresta e retorna a com menor distancia
            if (a.peso != b.peso) { //retorna com base no peso
                return a.peso < b.peso ? a : b;
            }
            else
                return aresta::comparaID(a,b) ? a : b; //desempata por id
                
        }

        //funcao recursiva para o algoritmo da parte 2
        aresta achaRecursivo(int inicio, int fim, vector<sistema>& sy_ordenado) {
            int meio = (inicio + fim) / 2;
            if (fim - inicio <= 3)
                return brutaMinimo(inicio, fim); //faz o brute force

            vector<sistema> sy_esq, sy_dir; //subvtores de sistemas ordenados em y para otimizacao
            double medianaX = sx[meio].x; //ponto mediana de x
            

            for (auto& s : sy_ordenado) { //otimiza a ordenacao
                if (s.x <= medianaX) {
                    sy_esq.push_back(s);
                } else {
                    sy_dir.push_back(s);
                }
            }

            aresta minEsq = achaRecursivo(inicio, meio, sy_esq); //continua recursao na esquerda
            aresta minDir = achaRecursivo(meio + 1, fim, sy_dir); //continua recursao na direita

            aresta arestaMin = setArestaMin(minEsq, minDir); //acha o minmo da direita/esq

            vector<sistema> strip; //contem os pontos em que dsitancia de x á mediana de x < min (nao considera distancia absoluta apenas em x)
            
            //mais rapido que ordenar strip apos monta-la (otimiza de nlog^2n para nlogn)
            for (auto s : sy_ordenado) { //acha strip utilizando vetor previamente ordenado por y e ajustado com base na mediana
                if (abs(s.x - medianaX) < arestaMin.peso) 
                    strip.push_back(s);
            }

            for (int i = 0; i < strip.size(); i++) { //usa propriedade de apenas olhar 7 vizinhos
                for (int j = i + 1; j < strip.size() && j <= i + 7; j++) {                        
                    double peso = sistema::calc_dist(strip[i], strip[j]);
                    aresta novoMin = aresta(strip[i], strip[j], peso);
                    arestaMin = setArestaMin(arestaMin, novoMin);
                }                       
            }
            
            return arestaMin;
        }

         aresta brutaMinimo(int inicio, int fim) {
            aresta arestaMin; //inicializado com peso = DBL_MAX (caso inicio = fim)
            
            for (int i = inicio; i <= fim; ++i) {
                for (int j = i + 1; j <= fim; ++j) {
                    double distAtual = sistema::calc_dist(sx[i], sx[j]);
                    aresta candidata = aresta(sx[i], sx[j], distAtual);

                    arestaMin = setArestaMin(arestaMin, candidata);
                }
            }
            return arestaMin;
        }

    
};


int main () {
    int x; cin >> x;
    for (int i = 0; i < x; i++) {
        int n, importantes; double tensaoMaxima;
        cin >> n >> importantes >> tensaoMaxima;

        vector<sistema> sistemas; //vetor de sistemas

        int id_counter = 0;
        for (int j = 0; j < importantes; j++ ) { //le os sistemas importantes
            sistema s; cin >> s.nome >> s.x >> s.y; s.id = id_counter++;
            sistemas.push_back(s);
        }
    
        DSU d = DSU(sistemas); //inicia o dsu
        vector<aresta> mst = d.kruskal(sistemas, tensaoMaxima); //resolve parte 1

        for (int j = importantes; j <  n; j++ ) { //le o restante dos sistemas
            sistema s; cin >> s.nome >> s.x >> s.y; s.id = id_counter++;
            sistemas.push_back(s);
            
        }

        for (auto a : mst) { //printa parte 1
            cout << a << endl;
        }

        CPP c = CPP(sistemas, tensaoMaxima);
        aresta ressonancia = c.achaPontoRessonante(); //resolve parte 2
        
        cout << "Ponto de Ressonância: " << ressonancia << endl << endl; //printa parte 2
    }
}