#ifndef PONTO_H
    #define PONTO_H

        typedef struct ponto_ PONTO;

        PONTO *ponto_criar (float x, float y);
        void ponto_apagar (PONTO **p);
        bool ponto_set (PONTO *p, float x, float y);
        float ponto_get_x (PONTO *p);
        float ponto_get_y (PONTO *p);
        void ponto_print (PONTO *p);
        float distancia(PONTO *pb, PONTO *pa);
        /*resolvi implementar a funcao distancia no TAD ponto devido a
        information hiding, já que apenas nesse TAD os dados são acessados 
        diretamente e podem assim ser melhor manipulados.*/
        
#endif