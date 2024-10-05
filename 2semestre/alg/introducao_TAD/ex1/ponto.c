#include <stdbool.h>
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>


struct ponto_ { 
    float px, py;
};

PONTO *ponto_criar (float x, float y) {
    PONTO *temp;

    if ((temp = malloc(sizeof(PONTO))) == NULL) 
        exit(1); 

    temp->px = x;
    temp->py = y;

    return temp;
}

void ponto_apagar (PONTO **p) {
    free(*p);
    *p = NULL;
}

bool ponto_set (PONTO *p, float x, float y) {
    if (p != NULL) {
    p->px = x;
    p->py = y;
    return 1;
    }
    return 0;
}

float ponto_get_x (PONTO *p) { 
    return p->px;
}

float ponto_get_y (PONTO *p) { 
    return p->py;
}

void ponto_print (PONTO *p) {
    printf("(%.1f, %.1f)", p->px, p->py);
}