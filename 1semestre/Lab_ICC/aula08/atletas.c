#include <stdio.h>
#include <wchar.h>

void bubble(int vet[], int n);
void swap(int *p1,int *p2);

int main (void) {
    int p_fixos[101], p_ordenados[100], col[101], empate[101], n;

    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%d", &p_fixos[i]);
        p_ordenados[i] = p_fixos[i];
    }

    bubble(p_ordenados, n);

    empate[1] = 0;
    for  (int i = 2; i<=n; i++) {
        if( p_ordenados[i] == p_ordenados[i-1]) {
            empate[i] = empate[i-1] + 1;
        }
        else empate[i] = empate[i-1];
    }

    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=n; j++){
            if (p_fixos[i] == p_ordenados[j]) {
                col[i] = j - empate[j];
                break;
            }
        }
    }

    empate[1] = 0;
    for (int i = 2; i<n; i++) {
        if (p_fixos[i] == p_fixos[i-1]) {
            empate[i] = empate[i-1] + 1;
        }
        else {
            empate[i] = empate[i-1];
        }
    }

    for (int i=1; i<=n; i++){
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i, p_fixos[i], col[i]);
    }

    return 0;
}

void bubble(int vet[], int n) {
    int swaps=1;
    while (swaps !=0) {
        swaps = 0;
        for (int i=1; i<=n-1; i++) {
            if (vet[i] < vet[i+1]) {
                int *p1 = &vet[i];
                int *p2 = &vet[i+1];
                swap(p1, p2);
                swaps++;
            }
        }
    }
} 

void swap(int *p1, int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
