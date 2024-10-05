#include <stdio.h>

int main () {
    int n;
    double result=0;

    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        if (i%2==1) {
            result += (double)1/i;
        }
        else {
            result -= (double)1/i;
        }
    }

    printf("%.4f\n", result);



    return 0;
}