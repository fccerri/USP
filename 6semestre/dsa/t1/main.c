#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int *read(int size) {
    int *aux;
    if ((aux = (int*)malloc(size*sizeof(int))) == NULL) {
        perror("error allocating the vector");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        scanf("%d", &(aux[i]));
    }

    return aux;
}

void print (int *vector, int size) {
    for (int i = 0; i< size; i++) {
        printf("%d ", vector[i]);
    }   
    printf("\n");
}

void printBool(bool b) {
    if (b == true)
        printf("SIM\n");
    else
        printf("NAO\n");
}

bool seqSearch(int vector[], int size, int find) {
    for (int i = 0; i < size; i++) {
        if (vector[i] == find)
            return true;
    }
    return false;
}

bool binSearch(int vector[], int size, int find) {
    int l = 0, r = size - 1;
    
    while (l <= r) {
        int mid = (r - l)/2 + l;
        
        if (vector[mid] == find) 
            return true;
        if (vector[mid] < find)
            l = mid + 1;
        else
            r = mid - 1;

    }

    return false;
}

bool recursiveBinSearch(int vector[], int l, int r, int find) {
    if (l > r)
        return false;

    int mid = (r - l)/2 + l;

    if (vector[mid] == find)
        return true;
    else if (vector[mid] < find)
        return recursiveBinSearch(vector, mid + 1, r, find);
    else
        return recursiveBinSearch(vector, l, mid - 1, find);
}


void swap (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int *inverse(int vector[], int size) {
    int l = 0, r = size - 1;
    int *tmp = (int*)malloc(size*sizeof(int));
    memcpy(tmp, vector, size*sizeof(int));

    while (l < r) {
        swap(&tmp[l], &tmp[r]);
        l++;
        r--;
    }

    return tmp;
}

int main () {
    int n; scanf("%d", &n);
    const int size = n;

    int *vector = read(size);


    int command = -1; //will be true in first iteration
    while (command) {
        int p; //to be searched

        scanf("%d", &command);

        switch (command) {
            case 1: {

                int *tmp = inverse(vector, size);
                print(tmp, size);

                free(tmp);
                tmp = NULL;

                break;
            }
            case 2: {
                scanf("%d", &p);
                printBool(seqSearch(vector, size, p));
                break;
            }
            case 3: {
                
                scanf("%d", &p);
                printBool(binSearch(vector, size, p));
                break;
            }
            case 4:
                scanf("%d", &p);
                printBool(recursiveBinSearch(vector, 0, size - 1, p));
                break;
            case 5:
                command = 0;
                break;        
        }
    }


    free(vector);
    vector = NULL;
}