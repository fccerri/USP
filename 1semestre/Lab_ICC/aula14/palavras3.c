#include <stdio.h>

void Palavras(int n, char l[], int index) {
    if (index == n) {
        printf("%s\n", l);
        return;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        l[index] = c;
        Palavras(n, l, index + 1); 
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