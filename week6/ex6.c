#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void print_signal(int signo){
    printf("Caught signal %d ", signo);
    if (signo == SIGKILL){
        printf("(SIGKILL)");
    } else if (signo == SIGSTOP){
        printf("(SIGSTOP)");
    } else{
        printf("(UNDEFINED)");
    }
    printf("\n");
}

int main(void) {
    int pipefd[2];
    pipe(pipefd);

    int child1_pid = fork();

    if (child1_pid == 0) { // child1

        int received_pid;
        close(pipefd[1]);
        read(pipefd[0], &received_pid, sizeof(int));
        close(pipefd[0]);
        printf("Child1: received pid: %d\n", received_pid);

        sleep(2);
        kill(received_pid, SIGSTOP);
        puts("Child1: sent SIGSTOP to child2");

        sleep(2);
        kill(received_pid, SIGCONT);
        puts("Child1: sent SIGCONT to child2");

        sleep(2);
        kill(received_pid, SIGKILL);
        puts("Child1: sent SIGKILL to child2");

    } else {
        int child2_pid = fork();
        if (child2_pid == 0) { // child2
            signal(SIGSTOP, print_signal);
            while (1){
                puts("\t Child 2 is alive");
                sleep(1);
            }
        } else { //parent
            printf("Parent: childs are %d %d\n", child1_pid, child2_pid);
            printf("Parent: sent pid: %d\n", child2_pid);
            write(pipefd[1], &child2_pid, sizeof(int));
            close(pipefd[1]);

            int child2_status;
            waitpid(child2_pid, &child2_status, 0);
            printf("Parent: child2 changed state (exit code - %d ", child2_status);
            if (child2_status == 9){
                puts("[killed])");
            }else{
                puts(")");
            }
        }
    }
    return 0;
}

/*
Example of output:
Parent: childs are 17968 17969
Parent: sent pid: 17969
Child1: received pid: 17969
	 Child 2 is alive
	 Child 2 is alive
Child1: sent SIGSTOP to child2
Child1: sent SIGCONT to child2
	 Child 2 is alive
	 Child 2 is alive
Child1: sent SIGKILL to child2
Parent: child2 changed state (exit code - 9 [killed])

 According to https://en.wikipedia.org/wiki/Signal_(IPC)#POSIX_signals SIGSTOP signal does not arrives to the process.
 SIGSTOP and SIGCONT are commands to scheduler to pause and continue the process respectively.
 
 This is well shown in the example of an output above: after sending SIGSTOP child 2 stops executing until receiving SIGCONT
 and bot signals were not caught by signal handlers
 */
