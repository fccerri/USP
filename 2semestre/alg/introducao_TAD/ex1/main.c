#include <stdbool.h>
#include "circulo.h"
#include "ponto.h"
#include <stdio.h>

int main (void) {
    PONTO *p = ponto_criar(0, 0); //declara as variaveis
    CIRCULO *r = circulo_criar(p, 0);
    float temp1, temp2;

    scanf("%f%f", &temp1, &temp2); //seta o ponto
    ponto_set(p, temp1, temp2);

    scanf("%f%f", &temp1, &temp2);  //seta o centro
    PONTO *temp_p = ponto_criar(temp1, temp2);
    circulo_set_ponto(r, temp_p);

    scanf("%f", &temp1); //seta o raio
    circulo_set_raio(r, temp1);

    printf("Ponto: "); //printa na formatacao correta
    ponto_print(p);
    printf("\nCirculo: Centro ");
    circulo_print_ponto(r);
    printf(", Raio = %.1f\n", circulo_get_raio(r));

    ponto_apagar(&p); //libera memoria
    circulo_apagar(&r);

    return 0;
}