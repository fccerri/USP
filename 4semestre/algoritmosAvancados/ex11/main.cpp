#include <bits/stdc++.h>

using namespace std;


struct DSU { //disjoint set uniom
    map<int, int> pai; //conjuntos
    int conjuntos; //qtd de conjuntos
    
    DSU(int atomos): conjuntos(atomos) {};

    void insert_bond(int n1, int n2) {
        make_set(n1);
        make_set(n2);
        if (unite(n1, n2) == true)
            conjuntos--;
    }

    void make_set(int n) {
        if (pai.find(n) == pai.end()) { //elemento não existe
            pai[n] = n; //cria elemento
        }    
    }

    int find(int id) {
        if (pai[id] == id)
            return pai[id];
        else
            return pai[id] = find(pai[id]); //compressao de caminho (otimizacao) 
    }

    //une os conjuntos de dois sistemas
    bool unite(int id1, int id2) {
        int raiz1 = find(id1);
        int raiz2 = find(id2);
        if (raiz1 != raiz2) {
            pai[raiz1] = raiz2;
            return true; //uniu
        }
        return false; //nao uniu (ja eram parte do mesmo conjunto)
    }
};

int main () {
    int x; cin >> x;
    vector<int> saida(x);
    while (x--) {
        int n, m; cin >> n >> m;
        DSU moleculas(n);
        for (int i = 0; i < m; i++) {
            int n1, n2; cin >>n1 >> n2;
            moleculas.insert_bond(n1, n2);
        }
        cout << moleculas.conjuntos << endl;
    }

}