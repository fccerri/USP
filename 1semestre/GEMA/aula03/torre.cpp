#include <bits/stdc++.h>
using namespace std;

int linhas[1000], colunas[1000];

int main () {
    int n, mat[1000][1000];
    cin >> n;

    for (int i=0;i<n;i++) 
        for (int j=0;j<n;j++) {

            cin >> mat[i][j];
        }
    
    for (int i=0;i<n;i++) 
        for (int j=0;j<n;j++) {

            linhas[i] += mat[i][j];
            colunas[j] += mat[i][j];
        }

        int maior = 0, atual=0;
    
        for (int i=0;i<n;i++) 
            for (int j=0;j<n;j++) {
            atual = linhas[i] + colunas [j] -2*mat[i][j];

            if (atual>maior)
             maior=atual ;


    }
    

    cout << maior;


    return 0;
}