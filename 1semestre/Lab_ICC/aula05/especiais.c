#include <stdio.h>
#include <math.h>

int main () {
    int grupo1, grupo2;

    for (int i =32; i<100; i++) {
        grupo1 = (i*i/100);
        grupo2 = i*i - grupo1*100;
        //printf("1:%d\n", grupo1);
        //printf("2:%d\n", grupo2);
        if ((grupo1 + grupo2)==i)
            printf("%d\n", i*i);
    }

    return 0;
}