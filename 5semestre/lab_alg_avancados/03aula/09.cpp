#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    vector<int> toblerone(n+1);
    vector<int>dp(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> toblerone[i];
    }

    int global = 0;
    dp[0] = toblerone[0];
    for (int i = 1; i <= n; i++) {
        dp[i] = toblerone[i]; 
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i-j] + toblerone[j], dp[i]);
        }
        global = max(dp[i], global);
    }
    
    cout << global;
}
