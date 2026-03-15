#include <bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t--){
        vector<int> solucoes(1000); solucoes[0] = 0;
        vector<bool> calculado(1000);
        vector<int> moedas(500, false);

        int n, valor; cin >> valor >> n;
        for (int i = 0; i < n; i++) {
            int moeda; cin >> moeda; moedas[i] = moeda;
        }
        

        for (int x = 1; x <= valor; x++) {
            solucoes[x] = INT_MAX;
            for (int moeda : moedas) {
                if (x - moeda >= 0) 
                solucoes[x] = min(solucoes[x], solucoes[x-moeda]+1);
                
            }
        }
        cout << solucoes[valor] << endl;    

    }
}