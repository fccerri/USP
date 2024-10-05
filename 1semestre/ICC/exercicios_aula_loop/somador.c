    #include <stdio.h>

    int main (void) {
        int n1, n2,  n2_decimal=0, n1_decimal=0, bit, resultado, valorbit=1;

        scanf("%d %d", &n1, &n2);

        while (n1-1) {
            scanf("%d", &bit);
        
            if (bit) {
                for (int i=1; i<=n1; i++) {
                    valorbit *=2;
                }
                
                n1_decimal = valorbit;
            }
            valorbit=1;
            n1--;
        } 

        scanf("%d", &bit);
        
        resultado = n1_decimal + bit;

        while (n2-1) {    
            scanf("%d", &bit);

            if (bit) {
                for (int i=1; i<=n2; i++) {
                    valorbit *=2;
                    
                }
              n2_decimal = valorbit;
            }
            valorbit=1;
            n2--;
        } 

        scanf("%d", &bit);

        resultado += n2_decimal + bit;

        printf("%d", resultado);


        return 0;
    }