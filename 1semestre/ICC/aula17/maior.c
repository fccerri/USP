#include <stdio.h>

int main (void) {
    float vet[10000], maior=0;
    int n;

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", vet[i]);
    }
    for (int i=0; i<n; i++) {
    if (maior<vet[i]){
            maior = vet[i];
        }
    }
    printf("%.2f", maior);   

    return 0; 
}