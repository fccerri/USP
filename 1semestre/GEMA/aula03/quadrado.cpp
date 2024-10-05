#include <bits/stdc++.h>
using namespace std;
int coluna[3], linha[3], dig1, dig2;

int main () {
    int mat[3][3];
   

    for (int i=0; i<3;i++) 
         for (int j=0;j<3;j++)
            cin >> mat[i][j];

    for (int i=0; i<3;i++)
        for (int j=0;j<3;j++) {

            linha[i] += mat[i][j];
            coluna[j] += mat[i][j];

            if (i==j) dig1 += mat[i][j];
        }
            dig2 = mat[0][2];
            dig2 += mat[1][1];
            dig2 += mat[2][0];



    if (linha[0]==linha[1] and linha[1]==linha [2]) {

        if (linha[0]==coluna[0] and coluna[0]==coluna[1] and coluna[1]==coluna[2]){

            if (dig1==coluna[0] and dig1==dig2)
                cout << "SIM";
            else {cout << "NAO";}

        }

        else {cout << "NAO";}

        }

        else {cout << "NAO";}
    

    return 0;
}