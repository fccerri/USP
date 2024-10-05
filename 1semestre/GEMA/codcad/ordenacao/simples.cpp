#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int v[1001], n;

    cin >> n;

    for (int i=0; i<n; i++) 
        cin >> v[i];

    sort(v,v+n);

    for (int i=0; i<n;i++) 
        cout << v[i] <<" ";

    return 0;
    
}