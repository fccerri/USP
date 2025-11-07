#include <bits/stdc++.h>

using namespace std;

int u; //ultrapassagens
struct carro {
    int inicio;
    int fim;
    int parcial;

    static const bool compara_inicio(carro &a,carro &b) {
        return a.inicio < b.inicio ? true : false;
    }
    static const bool compara_fim(carro &a,carro &b) {
        return a.fim < b.fim ? true : false;
    }  
};

void intercala(vector<carro> &v, int ini, int meio, int fim) {
    int i, j, k, n1, n2;
    
    // calculando tamanho dos subarranjos
    n1 = meio - ini + 1;
    n2 = fim - meio;
    
    // declarando subarranjos que serão intercalados
    vector<carro> L(n1 + 1), R(n2 + 1);

    // iniciando subarranjos a partir de v
    for (i = 0; i < n1; i++) {
        L[i] = v[ini + i];
    }
    L[n1].fim = 9999999; // inserindo sentinela
    
    for (j = 0; j < n2; j++){
        R[j] = v[meio + j + 1];
    }
    R[n2].fim = 9999999; // inserindo sentinela
    
    // intercalando arranjos
    i = j = 0;
    for (k = ini; k <= fim; k++) {
        if (L[i].fim <= R[j].fim) {

            v[k] = L[i];
            i++;
        } else {
            
            u += (n1 - i); //contabiliza ultrapassagem
            v[k] = R[j];
            j++;
        }
    }
}


void merge_sort(vector<carro> &v, int ini, int fim) {
  int meio = (ini + fim) / 2;
  if (ini < fim) { // existe mais de 1 elementok
    merge_sort(v, ini, meio);
    merge_sort(v, meio + 1, fim);
    intercala(v, ini, meio, fim);
  }
}


int main () {
    int x; cin >> x;
    vector<pair<int, int>> saida(x);
    for (int j = 0; j < x; j++) {
        int n; cin >> n; u = 0;
        vector<carro> carros;
        for (int i = 0; i < n; i++) {
            carro j; cin >> j.inicio >> j.fim;
            carros.push_back(j);
        }
        sort(carros.begin(), carros.end(), carro::compara_inicio); 

        merge_sort(carros, 0, carros.size() - 1);
        
        saida[j].first = j;
        saida[j].second = u;

    }

    sort(saida.begin(), saida.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b){
    return a.second > b.second;});

    for (int i = 0; i < x; i++) {
        cout << saida[i].first << " " << saida[i].second << endl;
    }
}