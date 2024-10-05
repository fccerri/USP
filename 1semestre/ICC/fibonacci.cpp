#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, n1, nn;
    cin >> n;
    n1 = 1;
    nn = 2;

    if (n>3){
        while (n!=3) {
            n--;
            nn = nn + n1;
            n1 = nn - n1;}

     cout << nn;}
        
    else if (n==3) {
        cout << 2;}
    
        else {
        cout << 1;}
        
return 0;}
    