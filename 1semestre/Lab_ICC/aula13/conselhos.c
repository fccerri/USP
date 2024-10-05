#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int AchaTam(FILE **fp, char nome[15]) {
    int tam;
    *fp = fopen(nome, "rb");

    fseek(*fp, 0, SEEK_END);
    tam = ftell(*fp);
    
    return tam;
}
void Operacao(char *str, char invasora[15]) {
    char *p; int size;
    p = strstr(str, invasora);
    
    int i =0;
    while ( &str[i] != p) {
        printf("%c", str[i]);
        i++;
    }
    i += strlen(invasora);
    if (str[i] ==' ') i++;
    while ( i < strlen(str)) {
        printf("%c", str[i]);
        i++;
    }

}

int main (void) {
    char nome[15], *str, invasora[15]; int tam;
    scanf(" %s %s", invasora, nome);
    FILE *fp;
    
    tam = AchaTam(&fp, nome);
    str = malloc((tam+1)*sizeof(char));
    
    rewind(fp);
    fread(str, sizeof(char), tam, fp);

    Operacao(str, invasora);


    fclose(fp);
    free(str);
    str = NULL;

    return 0;
}