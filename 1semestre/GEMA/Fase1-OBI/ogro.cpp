#include <bits/stdc++.h>
using namespace std;

int main () {
    short int E, D;
    cin >> E >> D;

    if (E>D) {
        cout << E+D << "\n";
    }
    else cout <<2*(D-E);

    return 0;

}