#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, n, ver;
    cin >> t;

    string a , b ,c;

    while (t!=0) {
        t--;
        cin >> n;
        cin >> a >> b >> c;
        ver=0;

        for (int i=0;i<a.size();i++) {

            if ((a[i]!=c[i]) and (b[i]!=c[i])) {
                ver++;
            }

        }

        if (ver!=0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
    
    return 0;
}