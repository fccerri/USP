#include <bits/stdc++.h>
using namespace std; //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

int main () {
    int n, k, remember = 0, temp;
    multiset<int> s;

    cin >> n >> k;
    multiset<int>::iterator it;

    for (int i=0; i<1000; i++) {
        cin >> remember; //guarda o valor a ser descartado na prox mediana
        s.insert(remember);

        if (i==0) {
            for (int i=0; i<k-1; i++) {
                cin >> temp;
                s.insert(temp); //estabelece os primeiros numeros a serem comparados
            }
        }
        else {
            cin >> temp;
            s.insert(temp); //add 1 num pra prox mediana
        }


        it=s.begin();
        for (int j=0; j<k/2; j++) { //estabelece um ponteiro na mediana
            it++;
            if (k%2==0) { //corrige caso k par
            it--;}
            // cout << *it << "ponteiro\n";
        }

        // cout << "set compleot : ";
        // for (set<int>::iterator st=s.begin(); it!=s.end();st++) {
        //     cout << *it << " ";
        // }
        // cout << "\n";
        
        cout << *it << " ";
        

        s.erase(remember);

    cout <<"\nloop" << i << "\n";
    }
    return 0;
}