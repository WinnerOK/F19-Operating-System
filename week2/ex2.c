#include <stdio.h>
#include <string.h>

#define MAX_LEN 2048

int main(int argc, char const *argv[]) {
    printf("Enter the string:\n");
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin); // get the whole string of len < MAX_LEN

    // strlen counts \n
    for (int i = strlen(str) - 2; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
    return 0;
}
