#include <bits/stdc++.h>
using namespace std;

int main () {
    int size, sum, n;
    vector <pair<int, int>> v;

    cin >> size >> sum;

    for (int i=1; i<=size; i++) {
        cin>> n;
        v.push_back(make_pair(n, i));
    }
    
    sort(v.begin(), v.end());
    auto it1 = v.begin();
    auto it2 = v.end();

    while ((it1->first + it2->first) != sum) { //esse jeito foi burro
        if ((it1->first + it2->first) > sum) it2--; 
            
        if ((it1->first + it2->first) < sum) it1++;  

        if(it1->first > it2->first or it1->second == it2->second) {
            label:
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

     if (it1->second == it2->second) goto label;

    printf("%d %d", it1->second, it2->second);

    return 0;
}