#include <stdio.h>
#include <stdlib.h>

void leia(FILE **fp) {
    char c = 10;
    for (int i =0; c!=EOF;) {
    c = fgetc(*fp);
    printf("%c", c);
    if (c == '\n') i++;
    if (i == 20) break;
    }
    printf("\n");
    
}

int main (int argc, char *argv[]) {
    FILE *fp;

    fp = fopen(argv[1], "r");
    
    if ( fp == NULL) {
        exit(1);
    }


    leia(&fp);

    fclose(fp);
    return 0;
}