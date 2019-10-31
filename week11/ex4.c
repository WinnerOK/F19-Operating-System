#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define log(msg)\
    do {perror(msg); return 0;} while (0);
#define filename "ex1"
#define input_filename filename ".txt"
#define output_filename filename ".memcpy.txt"

int main() {
    int input_file_descriptor = open(input_filename, O_RDONLY);
    int output_file_descriptor = open(output_filename, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR |S_IRGRP | S_IWGRP);

    struct stat *statistic = malloc(sizeof(struct stat));
    fstat(input_file_descriptor, statistic);
//    printf("%lu\n", statistic->st_size);
    unsigned long size = statistic->st_size;
    ftruncate(output_file_descriptor, size);

    char *input_file_map = mmap(NULL, size, PROT_READ, MAP_SHARED, input_file_descriptor, 0);
    if (input_file_map == MAP_FAILED) {
        close(input_file_descriptor);
        close(output_file_descriptor);
        log("Input map failed")
    }

    char *output_file_map = mmap(NULL, size, PROT_WRITE, MAP_SHARED, output_file_descriptor, 0);
    if (output_file_descriptor == MAP_SHARED){
        close(input_file_descriptor);
        close(output_file_descriptor);
        log("Output map failed")
    }

    memcpy(output_file_map, input_file_map, size);

    munmap(input_file_map, size);
    munmap(output_file_map, size);
    close(input_file_descriptor);
    close(output_file_descriptor);


//    ftruncate(input_file_descriptor, string_to_write_length);
//    char *addr = mmap(NULL, string_to_write_length, PROT_WRITE | PROT_READ, MAP_SHARED,
//                      input_file_descriptor, 0);
//
//    if (addr == MAP_FAILED) {
//        close(input_file_descriptor);
//        log("Map failed")
//    }
//
//    strcpy(addr, string_to_write);
//    munmap(addr, string_to_write_length);
    return 0;
}