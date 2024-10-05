#include <stdio.h>

int primo(int a) {
    if (a==1)
        return 0;
    for (int i=2; i*i<a; i++) {
        if (a%i==0) 
            return 0;
    }
    return 1;
}

int main () {
    int f, l, maiorPrimo=0;

    scanf("%d %d", &f, &l);

    for (int i=f; i<=l; i++) {
        if (primo(i)) {
            printf("menor primo: %d\n", i);
            maiorPrimo = i;
            
            for (int i=maiorPrimo; i<=l; i++) {
                if (primo(i))
                maiorPrimo = i;
            }
            break;
        }
    }

   
    if (!maiorPrimo) 
    printf("nenhum primo no intervalo");

    else  {  
    printf("maior primo: %d", maiorPrimo);}


    return 0;
}