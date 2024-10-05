#include <stdio.h>

void Palavras(int n, char l[], int index) {
        if (l[index] >'z') {
        l[index] = 'a';
        return;
        }

    printf("%s",l);
    printf("\n");

    for (int i = n-1; i>=0; i--) {
        l[i]++;
        Palavras(n, l, i);
    }    
    

}

int main (void) {
    int n; scanf("%d", &n);
    char l[n+1];
    for (int i=0; i<n;i++) {
        l[i] = 'a';
    }
    l[n] = '\0';
    Palavras(n, l, 0);

    return 0;
}