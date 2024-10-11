#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a,b) ((a) > (b)) ? &a : &b

void heapSort(int vet[], int tam);

void buildHeap(int vet[], int tam);

void heapify(int vet[], int id, int tam);

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
    int *vet = malloc(sizeof(int)*n); 
    for (int i =0; i<n; i++) scanf("%d", &vet[i]);

    double tempo; clock_t start = clock();
    heapSort(vet, n);
    tempo = endTime(start);

    for (int i = 0; i<n; i++) printf("%d ", vet[i]);
    printf("\ntempo de execução: %lf", tempo);

    free(vet);
    return 0;
}

void heapify(int vet[], int id, int tam) {
    int left = 2 * id + 1, right = 2 * id + 2, largest = id;


    if (left < tam && vet[id] < vet[left]) { //acha maior filho
        largest = left;
    }   
    if (right < tam && vet[largest] < vet[right]) {
        largest = right;
    } 
    if (largest == id) return;
    
    swap(&vet[largest], &vet[id]);
    heapify(vet,largest, tam);

}

void buildHeap(int vet[], int tam) {
    for (int i = ((tam-1)/2 - 1) ; i>=0; i--) {
        heapify(vet, i, tam); //deve estar errado    
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