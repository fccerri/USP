#include <bits/stdc++.h>
using namespace std;

int main (void) {
    set<int> var;
    int n, add;

    cin >> n;
    

    for (int i=0; i<n; i++) {
            cin >> add;
            var.insert(add);
        }

    cout << var.size();


    return 0;
}