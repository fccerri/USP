#include <stdlib.h>
#include <string.h>

/*Funcoes: 
- add
- sub
- potencia_de_10
disponibilizadas na disciplina
*/

#define max(a, b) ((a) > (b) ? (a) : (b))

// Soma de dois números representados por strings
char* add(char* str1, char* str2) {
    int tam = max(strlen(str1), strlen(str2));
    int carry = 0;
    int sum = 0;

    char* res = calloc(tam + 2, sizeof(char));

    // Adiciona zeros à esquerda para igualar o tamanho das strings
    char* tmp1 = calloc(tam + 1, sizeof(char));
    char* tmp2 = calloc(tam + 1, sizeof(char));
    memset(tmp1, '0', tam);
    memset(tmp2, '0', tam);
    strcpy(tmp1 + (tam - strlen(str1)), str1);
    strcpy(tmp2 + (tam - strlen(str2)), str2);

    for (int i = tam - 1; i >= 0; i--) {
        sum = carry + (tmp1[i] - '0') + (tmp2[i] - '0');
        res[i + 1] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {
        res[0] = carry + '0';
        free(tmp1);
        free(tmp2);
        return res;
    } else {
        free(tmp1);
        free(tmp2);
        return res + 1;
    }
}

// Subtração de dois números representados por strings
char* sub(char* str1, char* str2) {
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    int tam = max(tam1, tam2); 

    char* res = calloc((tam + 2), sizeof(char));
    memset(res, '0', tam + 1);

    int empresta = 0, i = tam1 - 1, j = tam2 - 1, k = tam;

    while (i >= 0 || j >= 0 || empresta) {
        int digito1 = (i >= 0) ? str1[i--] - '0' : 0;
        int digito2 = (j >= 0) ? str2[j--] - '0' : 0;
        digito2 += empresta;

        if (digito1 < digito2) {
            digito1 += 10;
            empresta = 1;
        } else {
            empresta = 0;
        }

        res[k--] = (digito1 - digito2) + '0';
    }

    while (*res == '0' && *(res + 1)) res++;

    return res;
}

// Multiplica um número, representado por uma string, por uma potência de 10
char* potencia_de_10(const char* str, int potencia) {
    int tam = strlen(str);
    char* res = calloc(tam + potencia + 1, sizeof(char));

    strcpy(res, str);
    for (int i = 0; i < potencia; i++) {
        res[tam + i] = '0';
    }
    res[tam + potencia] = '\0';

    return res;
}

char *separa_inf(char *str, int meio) {
    char *str_inf = malloc((meio+2)*sizeof(char));
    strcpy(str_inf,str + meio);
    return str_inf;
}

char *separa_sup(char *str, int meio) {
    char *str_sup = malloc((meio+2)*sizeof(char));
    str[meio] = '\0';
    strcpy(str_sup, str);
    return str_sup;
}

//resolver problemas de memorie leak 
char* multiplicacao(const char* str1, const char* str2) {

    int tam1 = strlen(str1), tam2 = strlen(str2), mul;
    char *result = malloc(sizeof(char)*(3));
    char aux[3];

    memset (result, '0', 2 );
    result[2] = '\0';

    for (int i = tam1 - 1 ; i >= 0; i--) {
        for (int j = tam2 - 1; j >= 0; j--) {

            mul = (str1[i] - '0')*(str2[j] - '0'); 
            aux[0] = (mul/10) + '0';
            aux[1] = (mul%10) + '0';
            aux[2] = '\0';


            char* temp = add(result, potencia_de_10(aux, tam1 + tam2 - i - j - 2));
            free(result);// - free invalid pointer??
            //se não usar uma variavel temporaria tem vazamento de memoria
            result = temp;
        }
           
    }
    int i = 0;
    while (result[i] == '0' && result[i + 1] != '\0') i++;
    char *resposta = malloc(sizeof(char)*(strlen(result)-i+1));
    strcpy(resposta, result+i);
    // free(result);// - free invalid pointer??

    return resposta;
}


char *karatsuba(char *str1, char *str2) {
    int m = max(strlen(str1), strlen(str2));
    int meio = m/2;

    if (m <= 1) {
        return multiplicacao(str1, str2);
    }

    char *str_sup1 = separa_sup(str1, meio);
    char *str_inf1 = separa_inf(str1, meio);
    char *str_sup2 = separa_sup(str2, meio);
    char *str_inf2 = separa_inf(str2, meio);

    char *z0 = karatsuba(str_inf1, str_inf2);
    char *z1 = karatsuba(add(str_inf1, str_sup1), add(str_inf2, str_sup2));
    //talvez seja strcat ao invez de add.
    char *z2 = karatsuba(str_sup1, str_sup2);

    free(str_sup1);
    free(str_inf1);
    free(str_sup2);
    free(str_inf2);

    char *p1 = potencia_de_10(z2, meio*2);
    char *p2 =  potencia_de_10(sub(sub(z1,z2), z0), meio);
    char *result = add(add(p1, p2), z0);

    // free(z0); - free invalid pointer
    // free(z1);
    // free(z2);
    free(p1);
    free(p2);

    return result;

    // return 
    // add(add(potencia_de_10(z2, meio*2),potencia_de_10(sub(sub(z1,z2), z0), meio) ), z0);    
}

