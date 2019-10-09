#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TO_ALLOCATE 1000*1024*1024

int main() {
    for (int i = 0; i < 10; ++i) {
        void *q = malloc(TO_ALLOCATE);
        memset(q, 0, TO_ALLOCATE);
        sleep(1);
    }
    return 0;
}
/*
daniil@daniil-Aspire-E5-575G:~/Coding/Innopolis courses/F19-Operating-System/week8$ ./ex2&  vmstat 1
[1] 22541
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  0 809728 10184648  69940 420876  101  559  1348   623  545  836 11  5 46 37  0
 1  0 809728 10184404  69940 420968    0    0     0     0 1711 3049  5  3 92  0  0
 0  0 809728 10184152  69940 420968   60    0    60     0 3565 4348  8  5 86  2  0
 1  1 808448 10183112  69948 420952 1156    0  1156   152 2796 3004  5  3 85  7  0
 0  0 807168 10181600  69948 420968 1704    0  1704     0 3051 4747 11  6 82  2  0
 0  0 807168 10181380  69948 420972  160    0   160     0 2484 3900  5  3 90  2  0
 0  0 807168 10181348  69948 420972    4    0     4     0 2942 2859  2  1 96  1  0
 0  0 807168 10181348  69948 420972    0    0     0     0 1855 2333  2  2 96  0  0
 0  0 806144 10181348  69964 420972   28    0    28    32  489 1099  2  1 96  2  0
 0  0 806144 10181348  69964 420972    0    0     0     0  331  644  1  1 99  0  0
 0  0 805376 10180836  69964 421000  464    0   464     0  692 1328  2  2 86  9  0
 0  0 805376 10180876  69964 420972    0    0     0     0  351  898  1  1 98  0  0
 0  0 805376 10180592  69964 420964   16    0    16     0  345  749  1  0 98  1  0

   Procs
       r: The number of runnable processes (running or waiting for run time).
       b: The number of processes in uninterruptible sleep.

   Memory
       swpd: the amount of virtual memory used. -- I ran the program twice, so I already have some memory in swap
       free: the amount of idle memory. -- this and following parameters are not stable, because there are a lot other processes using and freeing memory
       buff: the amount of memory used as buffers.
       cache: the amount of memory used as cache.

   Swap
       si: Amount of memory swapped in from disk (/s). -- varies since other processes require some data from the cache
       so: Amount of memory swapped to disk (/s). -- at the moment, when the computer had an overload, so is >0 but then only swapping to RAM were performed

   IO
       bi: Blocks received from a block device (blocks/s).
       bo: Blocks sent to a block device (blocks/s).

   System
       in: The number of interrupts per second, including the clock.
       cs: The number of context switches per second.

   CPU
       These are percentages of total CPU time.
       us: Time spent running non-kernel code.  (user time, including nice time)
       sy: Time spent running kernel code.  (system time)
       id: Time spent idle.  Prior to Linux 2.5.41, this includes IO-wait time.
       wa: Time spent waiting for IO.  Prior to Linux 2.5.41, included in idle.
       st: Time stolen from a virtual machine.  Prior to Linux 2.6.11, unknown.

*/
