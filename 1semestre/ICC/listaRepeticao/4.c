#include <stdio.h>
#include <math.h>

int main (void) {
    long long int denominador;
    int base=1;
    double serie =0, pi;
    for (int i =1; i<1000; i++) {
        denominador = base*base*base;
        if (i%2==1) {
            serie += (float)1/denominador;
        }
        else 
            serie -= (float)1/denominador;

        base += 2;
    }

    serie *= 32;
    pi = cbrt(serie);

    printf("%f", pi);

    return 0;
}