#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    while (n--) {
        string substring, current; cin >> current;
        int lenght = current.size();
        for (int i = lenght - 1; i > 0; i--) {
            string prefix = current.substr(0, i);
            string sufix = current.substr(lenght-i, i);
            if (sufix == prefix) {
                substring = prefix;
                break;
            }
            
        }
        cout << substring << endl;
    }
}