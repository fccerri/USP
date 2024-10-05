#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, xi[100], xf[100], yi[100], area=0, yf[100], verifier=false;

    cin >> n;

    for (int i=0;i<n;i++)  {
                cin >> xi[i] >> xf[i] >> yi[i] >> yf[i];}

    for (int x=1; x<100;x++) {
        for (int y=1; y<100; y++) {
            for (int i=0; i<n; i++) {
                if (xi[i]<=x && xf[i]>x && y>=yi[i] && y<yf[i]) {
                    verifier = true;
                    break;}
                    
            }
            
            if (verifier) {
                area++;
                verifier = false;
            }
        }
    }
    

    cout << area;

    return 0;
}

        


