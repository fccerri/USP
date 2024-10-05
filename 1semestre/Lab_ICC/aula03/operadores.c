#include <stdio.h>

int main () {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int n3=n1+n2;

    if ((n1>n2 && (n1-n2)%3==0) || (n2>n1 && n3>400) || (n1==n2 && n1%2)) {

        printf("%d", n3);
    }
    else {
        printf("Nenhuma condicao foi satisfeita");
    }



    return 0;
}