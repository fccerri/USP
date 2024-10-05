#include <stdio.h>


int main (void) { 
    int v[10002], *p, n;
    p = v;
    scanf("%d", &n);
    for (int i =0; i<n; i++) {
        scanf("%d", p++);
    }
    p--;
    for (int i =0; i<n; i++) {
        printf("%d ", *p);
        p--;
    }
    return 0;
}