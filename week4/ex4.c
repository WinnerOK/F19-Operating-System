#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/*
 * The code of this exercise is the same as 3rd exercise because function system
 * allows to call commands with parameters like 'ls -la' or 'cat text' and run processes in background
 * using & at the end like './ex2&'
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