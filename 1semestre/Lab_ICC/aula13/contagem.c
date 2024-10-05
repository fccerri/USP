#include <stdio.h> 
#include <string.h>  

int main (void) {
    char nome[10], parametro[20], aux[20] = ""; int count =0;
    scanf(" %s %s", nome, parametro);

    FILE *fp;
    
    fp = fopen(nome, "r");  
    
    while (feof(fp) == 0) {
        fscanf(fp, "%s", aux);
        strtok(aux, ",.:;");

        if (strcasecmp(parametro, aux) == 0)
            count++;
        
    }
    fclose(fp);
    printf("quantidade: %d\n", count);


    return 0;
}