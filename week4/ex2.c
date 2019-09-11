#include <stdio.h>
#include <unistd.h>

#define N 5

int main() {
    for (int i = 0; i < N; ++i) {
        fork();
    }
    sleep(5);
    return 0;
}

/*
3 forks
 ex2─┬─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2

 5 forks:
 ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
    │     │     │     └─ex2
    │     │     ├─ex2───ex2
    │     │     └─ex2
    │     ├─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2

 There are so much processes because each process in for loop forks one more time.
 * */