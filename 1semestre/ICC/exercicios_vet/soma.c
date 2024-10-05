#include <stdio.h>

int main (void) {
    int n, m, v1[30], v2[30], *p1 = v1, *p2 = v2;
    long long int binario1 =0, binario2 = 0;

    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++) {
        scanf("%d", p1++); 
    }
    p1 = v1;
    for (int i=0; i<n-1; i++) { //transforma pra binario
        binario1 += *p1++;
        binario1 <<= 1; 
    }
    binario1 += *p1;

    for (int i=0; i<m; i++) { //le o segund n
        scanf("%d", p2++); 
    }
    p2 = v2;
    for (int i=0; i<m-1; i++) { //transforma pra binario
        binario2 += *p2++;
        binario2 <<= 1; 
    }   
    binario1 += *p2;

    printf("%lld\n", binario1+binario2);
    
    return 0;
}