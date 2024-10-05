#include <iostream>
 
using namespace std;
 
int main() {
    int n, x, menor=1001, posicao=0;
    
    cin >> n;
    
    for (int i=0;i<n;i++) {
        cin >> x;
        if (x<menor) {
            menor = x;
            posicao=i;
        }
        
    }
    
    printf("Menor valor: %d\nPosicao: %d", menor, posicao);
    return 0;
}