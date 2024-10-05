#include <iostream>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k; 

    if (n < k) {
        cout << k;}
        else   {
        cout << ((n / k) + 1)*k;}

    return 0;
}

