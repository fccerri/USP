#ifndef TIMER_H
    #define TIMER_H
    #include <time.h>
    
    typedef struct timer_ TIMER ;
    void start_timer(TIMER *timer);
    double stop_timer(TIMER *timer);

#endif
