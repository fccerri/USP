#include <bits/stdc++.h>
#include <climits>
#include <iostream>

using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> criancas;
        for (int i = 0; i < n; i++) { //le as criancas
            int crianca; cin >> crianca; criancas.push_back(crianca);
        }

        sort(criancas.begin(), criancas.end()); //ordena

        int cabines = 0;
        int i = 0, j = n-1;
        while (i <= j) {
            cabines++; //add cabines
            if (i == j) break; //caso especial
            if (criancas[i] + criancas[j] <= x) { //incrementa i apenas se possivel utiliza-lo
                i++; //atualiza os ponteiros
            }
            j--;
        }   

        cout << cabines << endl;

    }
}