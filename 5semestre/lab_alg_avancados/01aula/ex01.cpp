#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    for (int j = 0; j < t; j++) {
        int n; cin >> n;
        pair<string, int> assuntos[n]; 
        for (int i = 0 ; i < n; i++) {
            cin >> assuntos[i].first >> assuntos[i].second;   
        }

        int d; cin >> d;
        string assunto; cin >> assunto;
        int pass = 1;
        for (auto a : assuntos) {
            if (a.first == assunto) {
                
                if (d >= a.second) {
                    cout << "Case " << j+1 << ": Yessss" << endl;
                    pass = 0; break;
                }
                else if (d >= a.second -5) {
                    cout << "Case "<< j+1 << ": Late" << endl;
                    pass = 0; break;
                }                
            }
        }
        if (pass)
            cout << "Case "<< j+1 << ": Do your own homework!" << endl;
    }
}
