#include <stdio.h>
#include <stdlib.h>


void *aloca( int n){
    int *p;
    p = (int*)malloc(n*sizeof(int));
    return p;
}
void entrada(int **vet, int *n) {
    scanf("%d", n);
    *vet = (int*)aloca(*n);
}

int main (void) {
    int n, *vet;  

    entrada(&vet, &n);

    for (int i =0; i<n; i++) {
        scanf("%d", &vet[i]);
    }
    for (int i =0; i<n; i++) {
        printf("%d ", vet[i]);

    }

    free(vet);
    vet = NULL;


    return 0;
}