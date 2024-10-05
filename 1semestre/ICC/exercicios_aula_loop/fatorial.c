#include <stdio.h>

int main (void) {
    int n, result=0;

    scanf("%d", &n);

    for (int i=5; i<=n; i*=5) {
        result += n/i;
    }

    printf("%d", result);
    
    return 0;
}