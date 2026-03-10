#include <bits/stdc++.h>

using namespace std;

int main () {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        long int x, y; cin >> x >> y;

        if (x%2) // x é impar -> total é impar -> impossivel dividir
            cout << "NO" << endl;
        else if (x == 0 && y%2) //total de moedas é par, mas x = 0 e y impar -> não da pra divir
            cout << "NO" << endl; 
        else //total de moedas é par e divisivel
            cout << "YES" << endl; 
    }
}