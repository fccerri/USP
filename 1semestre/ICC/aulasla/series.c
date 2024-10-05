#include <stdio.h>

int main(void) {
    int  x, sfat=2;
    long long int fatorial=1, potencia=1;
    double serie;

    scanf("%d", &x);

    serie = x;

    for (int i=1; i<20; i++ ) {
        potencia *= x*x*(-1);
       
        fatorial *=sfat*(sfat+1);
        sfat += 2;

        serie += potencia/fatorial + (double)(potencia%fatorial)/fatorial;    
    }        

    printf("%f", serie);

    return 0;
}