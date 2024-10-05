#include <stdio.h> 

void converta(int numero);

int main (void) {
    int n, entrada; scanf ("%d", &n);

    for (int i =0 ; i<n; i++) {
        scanf("%d", &entrada);
        converta(entrada);
    }

    return 0;
}

void converta(int numero) {
    int i=0, normal[15] =  {1000, 900, 500, 400, 100, 90,50, 40, 10, 9, 5, 4, 1};
    char romano[15] = {'M', 'C', 'D', 'C', 'C', 'X', 'L', 'X', 'X', 'I', 'V', 'I', 'I'};
                                   //M               //D                //C               //L               //X           //V
    while (numero !=0){
        while (normal[i] <= numero){
            numero -= normal[i];
            if (i%2==0) {
                printf("%c", romano[i]);
            }
            else {
                printf("%c", romano[i]);
                printf("%c", romano[i-1]);
            }
        }
    i++;

    }
    printf("\n");
}