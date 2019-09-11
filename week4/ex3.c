#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/*
 * Simple shell. It can't handle cd command because call should change working directory,
 * but in fact variable with working directory for the process stays the same.
 *
 * This shell is able to run commands without parameters
 */
int main(int argc, char *argv[]) {
    char buf[BUFFER_SIZE];
    printf("\"Shell\" started. Enter \"exit\" to end session\n");
    while (1) {
        fgets(buf, BUFFER_SIZE - 1, stdin);
        if (strncmp(buf, "exit\n", 5) == 0) {
            break;
        } else {
            system(buf);
        }
    }


    return 0;
}