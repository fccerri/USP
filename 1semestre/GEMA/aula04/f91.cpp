#include <bits/stdc++.h>
using namespace std;

int f91(int n){

        if (n <= 100) 
            return f91(f91(n + 11));

        else 
            return n-10;
    }

int main () {
    
    int n=1;
    
    while (n) {
        cin >> n;

        if (!n) break;

        printf("f91(%d) = %d\n", n, f91(n));

    }

    

    return 0;
}