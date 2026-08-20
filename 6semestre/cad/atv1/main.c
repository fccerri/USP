#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N_SONS 6
#define N_THREADS (N_SONS + 1)

sem_t semaphores[N_THREADS];
int tkn = 0;
int stay = 1;

void main_routine(int loops) {

    while (loops--) {

        int id = 0;
        tkn += 1;
        printf("ID: %d, tkn: %d, nxt: %d\n", id, tkn, id + 1);
        fflush(0);
        sem_post(semaphores + id + 1);
        sem_wait(semaphores + id); 
    }
    

    printf("\nFather's thread freeing the poor kids.\n\n");
	fflush(0);
    stay = 0;

    for (int i = 1; i < N_THREADS; i++) {
        sem_post(semaphores + i);
    }

}

void *son_routine(void *arg) {
    uintptr_t id = (uintptr_t)arg;

    sem_wait(semaphores + id); //first
    while (stay){

        tkn += 1;
        printf("ID: %ld, tkn: %d, nxt: %ld\n", id, tkn, (id + 1)%N_THREADS);
        fflush(0);
        sem_post(semaphores + (id + 1)%N_THREADS); //%n_treads prevent seg fault
        sem_wait(semaphores + id);
    }
        
        pthread_exit(0);

}

int main(int argc, char *argv[]) {
    pthread_t sons_handle[N_SONS];  

    int loops = 1;
    if (argc > 1) {
        int parsed = atoi(argv[1]);
        if (parsed > 0) {
            loops = parsed;
        }
    }
    
    for (int i = 0; i < N_THREADS ; i++){
        sem_init(semaphores + i, 0, 0);
    }

    for (int i = 1; i < N_THREADS; i++) {

        if (pthread_create(sons_handle + i - 1, 0, son_routine, (void *)(uintptr_t) i ) != 0) {
            printf("Error creating thread producer! Exiting! \n");
	    	exit(0);
        }
    } 

    main_routine(loops);

    printf("\nFather�s thread waiting for his kids.\n\n");
	fflush(0);

    for (int i = 0 ; i < N_SONS; i++) {
        pthread_join(sons_handle[i], 0);
    }

	getchar();

	printf("Thread pai saindo.\n");
	fflush(0);
	
	exit(0);	



}

