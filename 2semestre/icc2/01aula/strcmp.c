#include <stdio.h> 
#include <string.h>

int main (void) {
    const int N = 10000;
    char str1[N], str2[N];

    printf("Insira a string\n");
    scanf("%s", str1);

    for (int i =0; i < strlen(str1); i++) {
        str2[i] = str1[i];
    } 

    str2[strlen[str1]+1] = '/0';

    return 0;
}