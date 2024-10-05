#include <bits/stdc++.h>
using namespace std;

int saida[55];

int main () {
    int n, mina;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> mina;

        if (i > 0) saida[i-1] += mina;

        saida[i] += mina;

        if (i < n-1) saida[i+1] += mina;
    }

    for (int i=0;i<n;i++)
        cout << saida[i] << "\n";

    return 0;
}