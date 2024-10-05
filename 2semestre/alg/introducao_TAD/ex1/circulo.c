#include <stdbool.h>
#include "circulo.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

// é pra usar o ponto como TAD?
struct circulo_ {
    PONTO *pc;
    float rc;
};

CIRCULO *circulo_criar (PONTO *p, float raio) {
    CIRCULO *temp;

    if ((temp = malloc(sizeof(CIRCULO))) == NULL) 
        exit(1);

    temp->pc = p;
    temp->rc = raio;

    return temp;
}


bool  circulo_set_ponto (CIRCULO *c, PONTO *p) {
    if (c != NULL && p != NULL) {
    c->pc = p;
    return 1;
    }
    return 0;
}

bool circulo_set_raio (CIRCULO *c, float raio) {
    if (c != NULL) {
    c->rc = raio;
    return 1;
    }
    return 0;
}

PONTO *circulo_get_ponto (CIRCULO *c) {
    return c->pc;
}

float circulo_get_raio (CIRCULO *c) {
    return c->rc;
}
void circulo_apagar (CIRCULO **c){
    free(*c);
    *c = NULL;
}

void circulo_print_ponto (CIRCULO *c) {
    ponto_print(c->pc);
}