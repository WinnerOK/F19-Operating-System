#include <stdio.h>
#include <unistd.h>

int main() {
    int n = fork();
    int pid = getpid();
    if (n) {
        printf("Hello from parent [PID: %d]\n", pid);
    } else {
        printf("Hello from child [PID: %d]\n", pid);
    }
    return 0;
}
/*
exec 1
Hello from parent [PID: 5887]
Hello from child [PID: 5888]
exec 2
Hello from parent [PID: 5889]
Hello from child [PID: 5890]
exec 3
Hello from parent [PID: 5891]
Hello from child [PID: 5892]
exec 4
Hello from parent [PID: 5893]
Hello from child [PID: 5894]
exec 5
Hello from parent [PID: 5895]
Hello from child [PID: 5896]
exec 6
Hello from parent [PID: 5897]
Hello from child [PID: 5898]
exec 7
Hello from parent [PID: 5899]
Hello from child [PID: 5900]
exec 8
Hello from parent [PID: 5901]
Hello from child [PID: 5902]
exec 9
Hello from parent [PID: 5903]
Hello from child [PID: 5904]
exec 10
Hello from parent [PID: 5905]
Hello from child [PID: 5906]

 At my machine scheduler worked in a such way that parent function executed first.
 All PIDs are incrementing - it is the way the are chosen by the system
 */
