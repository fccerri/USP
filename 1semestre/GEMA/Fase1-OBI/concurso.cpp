#include <bits/stdc++.h>
using namespace std;



int main () {
    int k, n, notas[503];

    cin >> n >> k;

    for (int i = 1; i<=n; i++) {
        cin >> notas[i];
    }

   
    sort(&notas[1], &notas[n+1]);

    //  for (int i = 1; i<=n; i++) {
    //     cout << notas[i] << "\n";
    // }


    cout << notas[(n-k)+1];


    return 0;
}