#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {
    int child_pid = fork();
    if (child_pid == 0) {
        while (1) {
            printf("I am alive\n");
            sleep(1);
        }
    } else {
        sleep(10);
        kill(child_pid, SIGTERM);
        wait(NULL);
    }
    return 0;
}