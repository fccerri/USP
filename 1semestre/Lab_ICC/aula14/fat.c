#include <stdio.h>

long long unsigned int fat(int n){
    if (n==1)
        return 1;

    // printf("%d\n", n);
    return fat(n-1)*n;
}

int main (void) {
    int n; scanf("%d", &n);
    printf("%lld", fat(n));

    return 0;
}

