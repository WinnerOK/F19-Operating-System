#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define log(msg)\
    do {perror(msg); return 0;} while (0);

#define filename "ex1.txt"
#define string_to_write "This is a nice day"
#define string_to_write_length strlen(string_to_write)

int main() {
    int file_descriptor = open(filename, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR |S_IRGRP | S_IWGRP);
    ftruncate(file_descriptor, string_to_write_length);
    char *addr = mmap(NULL, string_to_write_length, PROT_WRITE | PROT_READ, MAP_SHARED,
                      file_descriptor, 0);

    if (addr == MAP_FAILED) {
        close(file_descriptor);
        log("Map failed")
    }

    strcpy(addr, string_to_write);
    munmap(addr, string_to_write_length);
    close(file_descriptor);
    return 0;
}