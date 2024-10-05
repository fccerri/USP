#include <stdio.h>

void Palavras(int n, char letra[]) {
    if (letra[n]>'z' || letra[0]>'z') {
    return;
    }

    if(n!=0) {
        printf("%c",letra[n] );
    }

    printf("%c",letra[0]);
    for (int i =1; i<n; i++) {
        letra[i] += 1;
        Palavras(i, letra);
        printf("\n");
        }
    
    printf("\n");
    letra[0] += 1;
    Palavras(n, letra);
   

}

int main (void) {
    int n; scanf("%d", &n);
    char l[n];
    for (int i=0; i<n;i++) {
        l[i] = 'a';
    }
    Palavras(n-1, l);

    return 0;
}