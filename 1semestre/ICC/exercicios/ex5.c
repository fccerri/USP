#include <stdio.h>

int main () {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a%2 == b%2) {

        if (a%2==0) {
            printf("o primeiro numero é par\n");
            printf("o segundo numero é par\n");
            printf("o resultado é %d, que é par\n", a*b);}
    
        else {
            printf("o primeiro numero é impar\n");
            printf("o segundo numero é impar\n");
            printf("o resultado é %d, que é impar\n", a*b);}
    
        
    }
    
    else {

        if (a%2) {
        printf("o primeiro numero é impar\n");
        printf("o segundo numero é par\n");}

        else{
        printf("o primeiro numero é par\n");
        printf("o segundo numero é impar\n");}

    printf("o resultado é %d, que é impar\n", a+b);
    
    }

    return 0;
}