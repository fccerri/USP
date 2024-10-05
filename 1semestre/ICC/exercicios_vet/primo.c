#include <stdio.h>

int main (void) {
    int q, primos[1500001], n; //primo = 1
    scanf("%d", &q);   //n primo = 0

    for (int i =0; i<1500000; i++) {
        primos[i] = 1;
    } 

    for (int i = 2; i*i<=1500000; i++) {
        if (primos[i] == 0 ) continue;
        for (int j = 2; i*j<=1500000; j++) {
            primos[j*i] = 0;
        }
    }

    while (q--) {
        scanf("%d", &n);
        if (primos[n]) printf("Sim\n");
        else printf("Nao\n");
    }
    
    return 0;
}