#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> torre(n);
    for (int i = 0; i < n; i++) cin >> torre[i];

    vector<long long> dp0(n), dp1(n); 

    dp0[0] = torre[0];  //quebrar direto
    dp1[0] = torre[0]; //com dano de queda

    for (int i = 1; i < n; i++) {
        // quebrar diretamente a i
        dp0[i] = min(dp0[i - 1], dp1[i - 1]) + torre[i];

        // usar dano de queda (altura i ou dano 1)
        long long dano_altura = max(0LL, torre[i] - i);
        int dano_minimo = max(0LL, torre[i] - 1);

        dp1[i] = min(dp0[i - 1] + dano_altura, dp1[i - 1] + dano_minimo);
    }

    cout << min(dp0[n - 1], dp1[n - 1]) << "\n";
    return 0;
}
