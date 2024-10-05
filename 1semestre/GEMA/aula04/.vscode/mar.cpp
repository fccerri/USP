#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,area=0, mat[5][102];
    bool verifier = false;

    cin >> n;

    for (int i=1; i<=n;i++) {
        for (int j=1;i<=4;i++) {
            cin >> mat[i][j]; }
    }

    for (int x=1; x<=100;x++) {

        for (int y=1; y<=100; x++) {

            for (int i=1; i<=n; i++) {
            
            if (x>=mat[i][1] and x<=mat[i][2] and y>=mat[i][3] and y<=mat[i][4])
                verifier = true;}
        }
        if (verifier) {
            area++;
            verifier = false;
        }
    }

    cout << area;

    return 0;
    }

    