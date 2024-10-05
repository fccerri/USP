#include <stdio.h>

int main () {
    int n;
    float a, b ,t;

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%f %f %f", &a, &b ,&t);

        if (t==0) 
            printf("A corrida ainda nao comecou\n");
        
        

        else  {
            
            if (a!=0 && b==0) 
                printf("O piloto B desistiu inesperadamente\n");

            else if (a!=0 && b!=0 && t<0)
                printf("De alguma forma os pilotos voltaram no tempo\n");

            else if (a==0 && b!=0)
                  printf("O piloto A desistiu inesperadamente\n");

            else if (a==b && a!=0) 
                printf("Os karts empataram, percorrendo cada %.2fkm\n", t/a);

            else if (a==b && b==0) 
                printf("Os dois pilotos nao querem competir\n");

            else if (a>b) 
                printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", (a-b)*t);

            else 
                printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", (b-a)*t);

            }            

    }

    return 0;
}