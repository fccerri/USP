#include <bits/stdc++.h>
using namespace std;

int main () {

    stack<int> st;

    vector<int> vet{1, 2, 3, 4};

    for (int i=0; i<4; i++) {
        st.push(vet[i]);
    }

    while(st.size()> 0) {
        int x = st.top();
        cout << x << " ";
        st.pop();
    }
}