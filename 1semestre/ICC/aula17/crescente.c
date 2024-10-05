#include <stdio.h>

void swap (int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main (void) {
    int n, v[10000], swaps = 1, *pi, *pii;
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    while (swaps!=0) {
        swaps = 0;
        for (int i=0; i<n-1; i++) {
            if (v[i] > v[i+1]) {
                pi = &v[i];
                pii = &v[i+1];
                swap ( pi, pii);
                swaps++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}