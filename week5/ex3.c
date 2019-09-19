#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_COUNT 2
//#define CUT 50000*6
#define CUT 10
int count = 0;

int consumer_sleep = 0;
int producer_sleep = 0;

int t = 0;

void *consumer() {
    while (1) {
        if (consumer_sleep) {
            continue;
        }
        while (count > 0) {
            count--;
//            printf("Taken. Left: %d\n", count);
//            sleep(0.01);
        }

        consumer_sleep = 1;
        producer_sleep = 0;
        if (t%CUT <=1){
            printf("Consumer alive %d\n", t);
        }
    }
    pthread_exit(NULL);
}

void *producer() {
    while (1) {
        if (producer_sleep) {
            continue;
        }

        while (count < MAX_COUNT) {
            count++;
//            printf("Produced. Stored: %d\n", count);
//            sleep(0.01);
        }

        consumer_sleep = 0;
        producer_sleep = 1;
        if (t%CUT <= 1){
            printf("Producer alive %d\n", t);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    pthread_t producer_t, consumer_t;
    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    while (1){
        t++;
    }
    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);
    exit(0);
}