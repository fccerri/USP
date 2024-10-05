#include <stdio.h>

int main (void) { 
    int entrada, minusculas = 0 , numericos = 0;

    while (entrada!=64) {
        scanf(" %d", &entrada);

        if (entrada>97 && entrada<122) {
            minusculas++;
        }
        else if (entrada>=0 && entrada <11)
            numericos++;
    
    }
    return 0;
}