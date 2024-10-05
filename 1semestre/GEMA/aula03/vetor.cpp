#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, vet[10];

    cin >> n;
    vet[0]=n;
    cout << "N[0] = " << vet[0] << "\n";

    for (int i=1;i<10;i++) {
        vet[i]=pow(2,i)*n;

        cout << "N[" << i<< "] = " << vet[i] << "\n";

    }


    return 0;
}