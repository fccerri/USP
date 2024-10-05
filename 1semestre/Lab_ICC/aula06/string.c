#include <stdio.h>

int main () {
    char string[26];
    scanf("%[^\n]s", string);

    for (char *p = string; *p!= '\0'; p++) {
        printf("%c\n", *p);  
    }

    return 0;
}