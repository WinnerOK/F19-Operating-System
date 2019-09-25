#include <stdio.h>
#include <unistd.h>

#include <string.h>

#define MAX_N 100

int main() {
    int pipefd[2];
    char buf1[] = "Hello, World!", buf2[MAX_N];

    printf("Buf1: %s\n"
           "Buf2: %s\n\n", buf1, buf2);

    if (pipe(pipefd) == -1){
        perror("pipe failure");
        return -1;
    }

    write(pipefd[1], buf1, strlen(buf1));
    close(pipefd[1]);

    read(pipefd[0], &buf2, MAX_N);

    printf("Buf1: %s\n"
           "Buf2: %s\n\n", buf1, buf2);

    close(pipefd[0]);

    return 0;
}
/*
 * Output:
Buf1: Hello, World!
Buf2:

Buf1: Hello, World!
Buf2: Hello, World!
 */