#include <bits/stdc++.h>

using namespace std;

int main () {
    int h, i = 12;
    cin >> h; 
    if (h == 0) { //caso base
        cout << 0;
        return 0;
    }
    priority_queue<int> meses;

    while (i--) { //le os centimetros por mes
        int centimetros; cin >> centimetros;
        meses.push(centimetros);
    }

    int sum = 0; 

    for (int j = 1; j <= 12; j++) {
        sum += meses.top(); //acumula os centimetros por mes a partir dos maiores 
        meses.pop();

        if (sum >= h) { //define quantos meses são necessários regar se possível
            cout << j;
            return 0;
        }
    }

    cout << "nao cresce";
}