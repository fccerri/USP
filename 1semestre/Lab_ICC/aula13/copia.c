#include <stdio.h> 
#include <stdlib.h>

int AchaTam(FILE **fp, char nome[15]) {
    int tam;
    *fp = fopen(nome, "rb");

    fseek(*fp, 0, SEEK_END);
    tam = ftell(*fp);
    
    return tam;
}

int main (void) {
    char nome[15], *str; int tam;
    scanf(" %s", nome);
    FILE *fp;
    
    tam = AchaTam(&fp, nome);
    str = malloc((tam+1)*sizeof(char));

    rewind(fp);
    fread(str, sizeof(char), tam, fp);
    printf("%s", str);

    fclose(fp);
    free(str);
    str = NULL;

    return 0;
}