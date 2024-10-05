#include "timer.h"
#include <time.h>

struct timer_ {
        clock_t start;
        clock_t end;
};

// Inicializa o timer
void start_timer(TIMER *timer) {
    timer->start = clock();
}

// Para o timer e calcula o tempo decorrido
double stop_timer(TIMER *timer) {
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}