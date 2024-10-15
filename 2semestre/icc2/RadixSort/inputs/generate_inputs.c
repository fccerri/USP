#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random(FILE *file, int n, int min_val, int max_val) {
    for (int i = 0; i < n; i++) {
        int num = (rand() % (max_val - min_val + 1)) + min_val;
        fprintf(file, "%d ", num);
    }
    fprintf(file, "\n");
}

void generate_ascending(FILE *file, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", i);
    }
    fprintf(file, "\n");
}

void generate_descending(FILE *file, int n) {
    for (int i = n; i > 0; i--) {
        fprintf(file, "%d ", i);
    }
    fprintf(file, "\n");
}

void generate_repeated(FILE *file, int n, int repeat_value) {
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", repeat_value);
    }
    fprintf(file, "\n");
}

void generate_mixed(FILE *file, int n) {
    for (int i = 0; i < n; i++) {
        int num = (rand() % 20001) - 10000; // números entre -10000 e 10000
        fprintf(file, "%d ", num);
    }
    fprintf(file, "\n");
}

int main() {
    srand(time(NULL));

    FILE *file;

    // Arquivo 1: Números aleatórios
    file = fopen("random1.in", "w");
    fprintf(file, "1000\n");
    generate_random(file, 1000, -10000, 10000);
    fclose(file);

    // Arquivo 2: Ordem crescente
    file = fopen("ascending1.in", "w");
    fprintf(file, "1000\n");
    generate_ascending(file, 1000);
    fclose(file);

    // Arquivo 3: Ordem decrescente
    file = fopen("descending1.in", "w");
    fprintf(file, "1000\n");
    generate_descending(file, 1000);
    fclose(file);

    // Arquivo 4: Números repetidos
    file = fopen("repeated1.in", "w");
    fprintf(file, "1000\n");
    generate_repeated(file, 1000, 1234); // repete o valor 1234
    fclose(file);

    // Arquivo 5: Mix de positivos e negativos
    file = fopen("mixed1.in", "w");
    fprintf(file, "1000\n");
    generate_mixed(file, 1000);
    fclose(file);

    return 0;
}
