#include <bits/stdc++.h>

using namespace std;

auto comparaPair = [](const pair<int, int> &a, const pair<int, int> &b) { //funcao para ordenar as entregas
        if (a.second != b.second) {
            return a.second < b.second; //ordena pelo fim
        }
        return a.first < b.first; //desempata pelo inicio
};

int main () {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;

        multiset<int> motoboys;
        while (x--) { //prenche o multiset de motoboys com proximo horario disponivel = 0
            motoboys.insert(0);
        }

        vector<pair<int,int>> entregas;
        for (int i = 0; i < n; i++) {
            int inicio, fim; cin >> inicio >> fim;
            entregas.push_back({inicio, fim});
        }

        sort(entregas.begin(), entregas.end(), comparaPair); //ordena as entregas por fim usando o inicio de desempate
        
        int max_entregas = 0;
        for (int i = 0; i < n; i++) {
            auto entrega_atual = entregas[i]; //olha para entrega atual
            auto it = motoboys.upper_bound(entrega_atual.first); //busca um motoboy com horario livre > horario de inicio da entrega
            if (it != motoboys.begin()) {//se existem motoboys livres
                it = prev(it); //ajusta para um motoboy lvire antes do inicio da entrega
                max_entregas++;
                //att horario livre do motoboy
                motoboys.erase(it); 
                motoboys.insert(entrega_atual.second); 
            }
        }
        
        cout << max_entregas << endl; 
    }
}