#include <asm-generic/errno.h>
#include <bits/stdc++.h>
using namespace std;
char placa[11];

int main () {
    int count =0; 
     cin >> placa;

     if (strlen(placa) != 7 and strlen(placa) != 8) {
        cout << 0;
        return 0;
     }

    for (int i =0; i<3; i++) { 
        if (placa[i] >= 'A' and placa[i] <= 'Z') count ++;
    }
    if (count == 3) {
        if (placa[3] == '-') {//br
            count =0;
            for (int i =4; i<8; i++) {
                if (placa[i] >= '0' and placa[i] <= '9') count ++;
            }
            if (count == 4) {
                cout << 1;
                return 0;
            }
        }
        
        else if (placa[3] >= '0' and placa[3] <= '9' ) {
            count =0;
            if (placa[4] >= 'A' and placa[4] <= 'Z' ) {
                for (int i =5; i<7; i++) {
                if (placa[i] >= '0' and placa[i] <= '9') count ++;
            }
                if (count == 2) {
                    cout << 2;
                    return 0;
            } 
            }
        }

        }

        cout << 0;
        return 0;
    }
    
    

