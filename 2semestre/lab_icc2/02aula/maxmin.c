#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))


void maxMin (int arr[], int inicio, int fim, int *max, int *min);

int main () {
    int arr[] = {12, 1234, 45, 67 , -1, 89, 2};
    int n = sizeof(arr)/sizeof(int);

    int max, min;

    maxMin(arr, 0, n-1, &max, &min);

    printf("max: %d, min : %d\n", max, min);



    return 0;
}

void maxMin (int arr[], int inicio, int fim, int *max, int *min) {

    if (inicio == fim) { //
        *max = arr[inicio];
        *min = arr[inicio];
    }
    else if (inicio + 1 == fim) { //com dois elementos definimos o maior e o menor
        *max = max(arr[inicio], arr[fim]);
        *min = min(arr[inicio], arr[fim]);
    }
    else {
        int meio = (inicio+fim)/2;
        int max1, min1, max2, min2;
    
        //conquista
        maxMin(arr, inicio, meio, &max1, &max2);
        maxMin(arr, inicio, meio + 1, &max1, &max2);

        *max = max(max1, max2);
        *min = min(max1, max2);
    }

}