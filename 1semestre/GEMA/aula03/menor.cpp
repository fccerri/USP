#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, menor, posicao;
    cin >> n;
    int vet[n];
    cin >> vet[n];

    for (int v=0;v<n;v++)
     cin >> vet[v];

    for (int i=1;i<n;i++) {
        if (vet[i-1]<vet[i]){
            menor=vet[i];
            posicao=1;
        }
                                                              
    }
    if (vet[0]<menor) menor=vet[0];

    cout << menor << "\n" << posicao;

    return 0;
}