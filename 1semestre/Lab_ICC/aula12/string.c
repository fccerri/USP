#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

char *aloca(int tam) {
    char *str;
    str = (char*)malloc(tam*sizeof(char));
    return str;

}
void leia(char **str, char **str1, char **str2) {
    scanf(" %[^\n]", *str);
    scanf(" %[^\n]", *str1);
    scanf(" %[^\n]", *str2);
    }

void operacao(char *str1, char *str2, char *parametro) {
    char *substring; int ff =0;

    substring = strstr(str1, parametro); //defini o ponteiro no primeiro parametro
        if (substring != NULL) {
            while (str1<substring)  {
                if (strcmp(parametro, "join") == 0) {
                printf("Cognito ergo sum");
                break;
                ff = 1;
            }
                printf("%c", *str1);
                str1++;
            }
        }
        else printf("%s", str1);
        
        substring = NULL;
        substring = strstr(str2, parametro); //procura o paramentro definindo um ponteiro pra ele 
        if (substring != NULL) {
            
        if (ff != 1) {      
        substring += strlen(parametro)+1;
            printf("%s", substring);//imprime do fim do parametro ao fim da string
        }}  
}

int main (void) {
    char *str1, *str2, *parametro;
    str1 = aloca(131);
    str2 = aloca(131);
    parametro = aloca(21);

    leia(&str1, &str2, &parametro);
    
    // printf("%s\n%s\n%s", str1, str2, parametro);

    operacao(str1, str2, parametro);

    free(str1);
    free(str2);
    free(parametro);

    return 0;
}