#include <stdio.h>
#include <time.h>
#define max(a,b) ((a) > (b)) ? &a : &b

void heapSort(int vet[], int tam);

void buildHeap(int vet[], int tam);

void heapify(int vet[], int id, int tam);

void printHeap(int n, int vet[], int id, int nivel);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double endTime(clock_t start){
    clock_t finish = clock();
    return ((double)(finish - start))/CLOCKS_PER_SEC;
}

int main () {
    int n; scanf("%d", &n); 
    int vet[30], visitados[30]; 
    for (int i =0; i<n; i++) {
        scanf("%d", &vet[i]);
        visitados[i] = 0;
    }
    printHeap(n, vet, 0, 0);
    printf("\n");

    // double tempo; clock_t start = clock();
    heapSort(vet, n);
    printHeap(n, vet, 0, 0);

    // tempo = endTime(start);

    // for (int i = 0; i<n; i++) printf("%d ", vet[i]);
    // printf("\ntempo de execução: %lf", tempo);

    return 0;
}

void heapify(int vet[], int id, int tam) {
    int left = 2 * id + 1, right = 2 * id + 2, min = id;


    if (left < tam && vet[id] > vet[left]) { //acha maior filho
        min = left;
    }   
    if (right < tam && vet[min] > vet[right]) {
        min = right;
    } 
    if (min == id) return;
    
    swap(&vet[min], &vet[id]);
    heapify(vet,min, tam);

}

void buildHeap(int vet[], int tam) {
    for (int i = ((tam-1)/2 - 1) ; i>=0; i--) {
        heapify(vet, i, tam);     
    }
}

void heapSort(int vet[], int tam) {
    buildHeap(vet, tam);
    int first = 0;
    
    for (int i = tam - 1; i > 0; i--) {
        swap(&vet[0], &vet[i]);
        heapify(vet, 0, i);
    }
}

void printHeap(int n, int vet[], int id, int nivel) {
    if (id >= n) return;

    for (int i = 0; i<nivel; i++) {
        printf("*");
    }
    if (nivel > 0) printf(" ");
    printf("%d\n", vet[id]);

    printHeap(n, vet, 2*id +1, nivel+1); //filho da esquerda

    printHeap(n, vet, 2*id +2, nivel+1);// filho da direita

}