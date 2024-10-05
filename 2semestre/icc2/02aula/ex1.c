#include <stdio.h>
#include <string.h>

float strtofloat(char *string, int base) {
    float num = 0, mult = 1;
    for (int i = strlen(string) - 1; i>= 0; i--) {
        num += (string[i]-48)*mult;
        mult *= base;       
    }
    return num;
}

int main (void) {
    int base, tam;
    scanf(" %d%d", &base, &tam);
    char str[tam];
    scanf("%s", str);
    // printf("%s\n", str); 

    printf("%f", strtofloat(str, base));

    return 0;


}