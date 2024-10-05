#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, cube;
    multiset<int> s;
    multiset<int>::iterator it;

    cin >> n;
    cin >> cube;
    s.insert(cube);

    for (int i=0; i<n-1; i++){
        cin >> cube;
        it=s.upper_bound(cube);

        if (it!=s.end()){
        }
        
 }
    cout << s.size() << "\n";
    return 0;
}