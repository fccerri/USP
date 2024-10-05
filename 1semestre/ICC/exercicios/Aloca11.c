#include <stdio.h>
#include <stdlib.h>

int main () {
    int *mat, n, m;
    scanf("%d%d", &n, &m);

    mat = malloc(n*m*(sizeof(int)));

for (int i =0; i<n; i++) {
    for (int j=0; j<m; j++) {   
        mat[i*m+j]
    }
}
}