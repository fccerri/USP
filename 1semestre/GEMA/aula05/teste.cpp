#include <bits/stdc++.h>
using namespace std;

int exp(int a, int b) {

    if (b == 1){
        return a;
    }

    int h=1;
    h = exp(a, b/2);
    h *= h;

    if (b%2) {
        h*=a;
    }

    return h;
    
}

int main () {
    int a, b;

    cin >> a >> b;

    cout << exp(a, b);

    return 0;

}