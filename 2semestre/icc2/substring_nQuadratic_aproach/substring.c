#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a,b) (a) < (b) ? a : b


int main () {
    int n, *vet; scanf("%d", &n);
    vet = malloc(n*sizeof(int));

    for (int i =0; i<n; i++) 
        scanf("%d", &vet[i]);

    int min = INT_MAX, sum = 0;
    for (int range = 1; range<=n; range++) { //seta o range
        for (int i = 0; i<=n-range; i++) { //seta o inicio da substring
            for (int j = i; j<range+i; j++) //percorre do inicio ao fim da substring
                sum += vet[j];

        min = min(min,sum);
        sum = 0;
        }
    }  
    printf("%d\n", min);

}