#include <bits/stdc++.h>
using namespace std;

int main () { //set demora mto -> deu n 
    int size, sum, n;
    multiset <pair<int, int>> s;

    cin >> size >> sum;

    for (int i=1; i<=size; i++) {
        cin>> n;
        s.insert(make_pair(n, i));
    }
    auto it1 = s.begin();
    auto it2 = s.end();
    it2--;

    while ((it1->first + it2->first) != sum) {
        if ((it1->first + it2->first) > sum) it2--; 
            
        if ((it1->first + it2->first) < sum) it1++;  

        if(it1->first > it2->first || it1->first > sum || 2*it2->first < sum) {
            label:      
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

     if (it1->second == it2->second) goto label;

    printf("%d %d", it1->second, it2->second);

    return 0;
}