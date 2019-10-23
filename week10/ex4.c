#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

#define NAME_LENGTH 512
#define CMD_LENGTH 512

int main() {
    DIR* tmp = opendir("tmp");
    struct dirent *dir = readdir(tmp);
    struct stat file;
    char cmd[CMD_LENGTH] = "rm -f ex4.txt"; // remove file ignoring non-existent
    system(cmd);

    while (dir != NULL){
        if (dir->d_name[0] != '.'){ // a file read
            char name[NAME_LENGTH];
            sprintf(name, "./tmp/%s", dir->d_name);
            stat(name, &file);
            if (file.st_nlink >= 2){
                sprintf(cmd, "echo \"[%s links: %ld]\" >> ex4.txt", name, file.st_nlink);
                system(cmd);

                unsigned int inode = file.st_ino;
                sprintf(cmd, "find -inum %u >> ex4.txt", inode);
                system(cmd);
            }

        }

        dir = readdir(tmp);
    }

    return 0;
}