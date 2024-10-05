#include <bits/stdc++.h>
using namespace std;




int main () {
    int n, q; cin >> n >> q;
    int x[2] = { 1, -1, };
    int y[2] = { 1, -1, };

    int vet[n+2][n+2];

    for (int i =0; i<=n+1; i++) { //cria buffer
        for (int j=0; j<=n+1; j++) {
            vet[i][j] =0;
        }
    }
    for (int i =1; i<=n; i++) { //  
        for (int j=1; j<=n; j++) {
            scanf("%1d", &vet[i][j]);
        }
    }

    for (int f =0; f<q; f++) { //repete q vezes
        for (int i =1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int count =0;
            count += vet[i][j+1];
            count += vet[i][j-1];
            count += vet[i+1][j+1];
            count += vet[i-1][j-1];
            count += vet[i+1][j];
            count += vet[i-1][j];
            count += vet[i-1][j+1];
            count += vet[i+1][j-1];

             if (vet[i][j] ==0 and count == 3) { //faz as trocas nescesarias
                    vet[i][j] = 1;
                }
            if (vet[i][j] == 1 and (count <2 or count >3 )) {
                  vet[i][j] = 0;  
            }



            // for (int k =0; k<2; k++) {
            //     count += vet[i][j+y[k]]; 
            //     count += vet[i+x[k]][j];
            //     for (int l = 0; l<2; l++) { //acessa as casas adjacente 
                    
                // }
               
            // }

        }
    }
    }
    for (int i =1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << vet[i][j];
            if (j==n) cout <<"\n";
        }
    }



    return 0;
}