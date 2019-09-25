#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define MAX_N 100

int main() {
    int pipefd[2];
    char buf1[] = "Hello, World!", buf2[MAX_N];

    printf("Buf1: %s\n"
           "Buf2: %s\n\n", buf1, buf2);

    if (pipe(pipefd) == -1) {
        perror("pipe failure");
        return -1;
    }

    if (fork() == 0) { // child
        close(pipefd[1]); // will not write
        read(pipefd[0], &buf2, MAX_N);
        printf("Child:\n"
               "\tBuf1: %s\n"
               "\tBuf2: %s\n\n", buf1, buf2);
    } else { //parent
        close(pipefd[0]); // will not read
        write(pipefd[1], buf1, strlen(buf1));
        close(pipefd[1]);
//        printf("Parent:\n"
//               "\tBuf1: %s\n"
//               "\tBuf2: %s\n\n", buf1, buf2);
        wait(NULL); //wait for child to terminate
        // int status
        // wait(&status) // status will contain a termination code of a child
    }


    return 0;
}