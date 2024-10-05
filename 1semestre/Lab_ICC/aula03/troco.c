#include <stdio.h>

int main () {
    int valor;
    scanf("%d", &valor);
    
        printf("%d nota(s) de R$ 200\n", valor/200);
        valor-= (valor/200)*200;  

        printf("%d nota(s) de R$ 100\n", valor/100);
        valor-= (valor/100)*100; 
   
        printf("%d nota(s) de R$ 50\n", valor/50);
        valor-= (valor/50)*50;  
    
        printf("%d nota(s) de R$ 20\n", valor/20);
        valor-= (valor/20)*20;  
    
        printf("%d nota(s) de R$ 10\n", valor/10);
        valor-= (valor/10)*10;  
    
        printf("%d nota(s) de R$ 5\n", valor/5);
        valor-= (valor/5)*5;  
    
        printf("%d nota(s) de R$ 2\n", valor/2);
        valor-= (valor/2)*2;  

        printf("%d moeda(s) de R$ 1\n", valor/1);
        valor-= (valor/1)*1; 
    



    return 0;
}