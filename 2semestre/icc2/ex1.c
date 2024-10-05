#include <stdio.h>
#include <string.h>

int chartoint(char c) {
    int num = -2;
    if (c >= '0' && c <= '9') {
        num = c - '0';
    }
    else if (c >= 'a' && c <= 'z') {
        num = c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'Z') {
        num = c - 'A' + 10;
    }
    else if(c == '-')
        num = -1;

    return num;
}

float strtofloat(char *string, int base) {
    float num = 0, mult = 1, value;
    for (int i = strlen(string) - 1; i>= 0; i--) {
        value = chartoint(string[i]);

        if (value >= 0) {
            num += value*mult;
            mult *= base;
        }

        else if (value == -1)    
            num *= -1;
    }
    return num;
}

int main (void) {
    int base; char str[80];
    scanf("%d %s", &base, str);

    printf("%f", strtofloat(str, base));

    return 0;
}