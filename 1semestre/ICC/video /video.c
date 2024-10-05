#include <stdio.h>

int main (void) {
    int n; scanf("%d", &n);
    int vetor[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    int trocas = 1;

    while (trocas!=0) {
        trocas = 0;
        for (int i = 0; i<n-1; i++) {
            if (vetor[i] > vetor[i+1]) {
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                
                trocas++;
            } 
        }
    }

    for (int i=0; i<n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}