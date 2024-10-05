#include <stdbool.h>
#include <math.h>
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

float distancia(PONTO *pb, PONTO *pa) { 
    float dist_x, dist_y;

    dist_x = pow((pb->px - pa->px), 2);
    dist_y = pow((pb->py - pa->py), 2);

    return sqrt(dist_x + dist_y);
}
/*resolvi implementar a funcao distancia no TAD ponto devido a
information hiding, já que apenas nesse TAD os dados são acessados 
diretamente e podem assim ser melhor manipulados.*/