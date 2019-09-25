#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void catch_function(int signo) {
    printf("Caught signal %d (SIGINT)\n", signo);
}

int main(void) {
    signal(SIGINT, catch_function);

    while (1){
        sleep(5);
    }
    return 0;
}