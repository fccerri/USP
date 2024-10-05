#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main () {
    int n;
    double l;

    scanf("%d %lf", &n, &l);
    printf("%lf", (n*pow(l,2))/(4*tan(M_PI/n)));


    return 0;
}