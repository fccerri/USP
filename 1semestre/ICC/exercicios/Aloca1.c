#include <stdio.h>
#include <stdlib.h>

int main (void) {
int **mat, *p, n, m;
scanf("%d%d", &n, &m);

mat = malloc(n*(sizeof(int*)));
p = malloc(n*m*(sizeof(int)));

for (int i=0; i<n; i++) {
    mat[i] = p +i*m;
}

for (int i =0; i<n; i++) {
    for (int j = 0; j<m; j++) {
        mat[i][j] = i+j;
    }
}

for (int i =0; i<n; i++) {
    for (int j = 0; j<m; j++) {
    printf("%d ", mat[i][j]);
    if (j==m-1)
      printf("\n");  
    }
}
free(mat);
free(p);

    return 0;
}