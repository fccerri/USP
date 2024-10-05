  #include <bits/stdc++.h>
using namespace std;

int main () {
    int n, somador=0;
    cin >> n;

    int vetor[n];

    for (int i=0;i<n;i++) {
      cin >> vetor[i];}
      
        for (int x=0;x+2<n;x++) {
          
            if (vetor[x] && !vetor[x+1] && !vetor[x+2]) {
            somador++;
            x++;
            
        }
    }
        
    cout << somador;

    return 0;
}