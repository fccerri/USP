#include <bits/stdc++.h>
using namespace std;

int acao (int n,int k) {
    if (n>k) {
        if (n%2==0) 
          return acao(n/2, k)*2;                          
        
        else 
            return  acao(n/2, k) + acao((n/2) +1, k);
    }
    else return 1;
}

int main () {
    int n, k;

    while (n) {
        cin >> n >> k;
        
        if (!n) break;

        cout << acao(n, k) << "\n";
    }


    return 0;
}