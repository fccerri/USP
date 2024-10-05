#include <stdio.h>


int main (void) {
    int bitmap, n, manobra;
    char caracter, str[15];
    scanf("%d", &n);

    for (int i = 0; i<n; i++) {

        scanf("%s", str);
        bitmap = 0;
        // printf("%s\n", str);
        // continue;

        for (int i =0;; i++) {
            if (str[i] == '\0') break;
            caracter = str[i]; 
            manobra = 1;
            caracter -= 97;
            bitmap ^= (manobra <<= caracter); 
        }

        if ((bitmap & (bitmap-1)) == 0)
            printf("%s eh um palindromo\n", str);
        
        else printf("%s nao eh um palindromo\n", str);

    }

    return 0;
}