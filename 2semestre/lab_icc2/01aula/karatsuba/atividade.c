#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct timer_ {
        clock_t start;
        clock_t end;
    } TIMER ;

void start_timer(TIMER *timer) {
    timer->start = clock();
}

// Para o timer e calcula o tempo decorrido
double stop_timer(TIMER *timer) {
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}

char* multiplicacao(const char* str1, const char* str2);

char* karatsuba(char* str1, char* str2);

int main() {
    char *str1 = malloc(sizeof(char)*10000);
    char *str2 = malloc(sizeof(char)*10000);
    TIMER timer;

    scanf(" %s %s", str1, str2);

    str1 = realloc(str1, strlen(str1)*sizeof(char));
    str2 = realloc(str2, strlen(str2)*sizeof(char));


    start_timer(&timer);
    char *result = multiplicacao(str1, str2);
    printf("tempo de execução convencional: %lf\n", stop_timer(&timer));
    printf("Resultado: %s\n", result);

    start_timer(&timer);
    result = karatsuba(str1, str2);
    printf("tempo de execução karatsuba: %lf\n", stop_timer(&timer));    
    printf("Resultado: %s\n", result);
   
   free(str1);
   free(str2);
   //free(result);// - free invalid pointer??

   return 0;
}
