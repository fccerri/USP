#include <stdio.h>

int main (void) {
    int n, m, cont = 0;
    scanf("%d", &n);
    int vn[n], vab[n]; //vetor 1 + vetor a-b

    for (int i=0; i<n; i++) { //le vetor 1
        scanf("%d", &vn[i]);
    }
    scanf("%d", &m);
    int vm[m]; // vetor 2

    for (int i=0; i<m; i++) { //le vetor 2
        scanf("%d", &vm[i]);
    }

    printf("intersecao: ");
    for (int i=0; i<n; i++) { //percorre o vetor 1
        int j = 0; //o ultimo j pode ser acessado dps do loop
        while (j<m) { //percorre o vetor 2
            if (vn[i]==vm[j]) { //encontra intersecção 
                printf("%d ", vn[i]);
                break; }
            j++;
        }
        if (vn[i]!=vm[j]){ //se não ouver  intersecção 
            vab[cont] = vn[i]; //vn[i] pertence ao conjunto a- b
            cont++;
        }
            
    }
    if (cont == n) printf("vazio"); 
    printf("\na - b: ");
    if (cont == 0){
        printf("vazio");
        return 0;
    }

    for (int i=0; i<cont; i++) {
        printf("%d ", vab[i]);
    }
    
    return 0;
}
