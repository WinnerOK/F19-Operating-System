#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void print_signal(int signo){
    printf("Caught signal %d ", signo);
    if (signo == SIGKILL){
        printf("(SIGKILL)");
    } else if (signo == SIGSTOP){
        printf("(SIGSTOP)");
    } else if (signo == SIGUSR1){
        printf("(SIGUSR1)");
    } else{
        printf("(UNDEFINED)");
    }
    printf("\n");
}

void catch_function(int signo) {
    print_signal(signo);
}

int main(void) {
    signal(SIGKILL, catch_function);
    signal(SIGSTOP, catch_function);
    signal(SIGUSR1, catch_function);


    while (1){
        sleep(5);
    }
    return 0;
}
/*
daniil@daniil-Aspire-E5-575G:~/Coding/Innopolis courses/F19-Operating-System/week6$ !gcc
gcc -std=c11  main.c && ./a.out&
[2] 8089
daniil@daniil-Aspire-E5-575G:~/Coding/Innopolis courses/F19-Operating-System/week6$ kill -SIGUSR1 8089
daniil@daniil-Aspire-E5-575G:~/Coding/Innopolis courses/F19-Operating-System/week6$ 
[2]+  User defined signal 1   gcc -std=c11 main.c && ./a.out

The last line means that 2nd background task ([2]) recieved ([+]) a user defined signal 1 
 and shows what command created a process

 */