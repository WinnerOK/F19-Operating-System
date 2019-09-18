#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_THREADS 10

void * print_hello_world(void * tid)
{
    printf("Greetings from thread %d\n", (int)tid);
    pthread_exit(NULL);
}
int main(int argc, char * argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    for(i=0; i < NUMBER_OF_THREADS; i++) {

        printf("Main. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void * )i);
        if (status != 0) {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
        pthread_join(threads[i], NULL); // added
    }
    exit(0);
}

/*
Main. Creating thread 0
Main. Creating thread 1
Greetings from thread 0
Main. Creating thread 2
Greetings from thread 1
Main. Creating thread 3
Main. Creating thread 4
Greetings from thread 3
Main. Creating thread 5
Greetings from thread 4
Main. Creating thread 6
Greetings from thread 5
Main. Creating thread 7
Greetings from thread 6
Main. Creating thread 8
Greetings from thread 7
Main. Creating thread 9
Greetings from thread 8

The order of output differs, because execution order depends only on scheduler

-------------------------
Main. Creating thread 0
Greetings from thread 0
Main. Creating thread 1
Greetings from thread 1
Main. Creating thread 2
Greetings from thread 2
Main. Creating thread 3
Greetings from thread 3
Main. Creating thread 4
Greetings from thread 4
Main. Creating thread 5
Greetings from thread 5
Main. Creating thread 6
Greetings from thread 6
Main. Creating thread 7
Greetings from thread 7
Main. Creating thread 8
Greetings from thread 8
Main. Creating thread 9
Greetings from thread 9

Output ordered since before creation of a new thread program waits previous to finish
*/