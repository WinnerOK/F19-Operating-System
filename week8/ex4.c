#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <stdio.h>

#define TO_ALLOCATE 1000*1024*1024

int main() {
    puts("Utime\tStime\tmaxrrs\tixrrs\t"
         "idrss\tisrrs\tminflt\tmajflt\t"
         "nswap\tinblock\toutblock\tmsgsnd\t"
         "msgrcv\tnsignals\tnvcsw");
    for (int i = 0; i < 10; ++i) {
        void *q = malloc(TO_ALLOCATE);
        memset(q, 1, TO_ALLOCATE);
        struct rusage *usage = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        struct timeval utime = usage->ru_utime;
        struct timeval stime = usage->ru_stime;
        printf("%5ld\t%5ld\t%5ld\t%5ld\t"
               "%5ld\t%5ld\t%6ld\t%6ld\t"
               "%5ld\t%7ld\t%7ld\t%10ld\t"
               "%6ld\t%8ld\t%5ld\t\n",
               utime.tv_usec, stime.tv_usec, usage->ru_maxrss, usage->ru_ixrss,
               usage->ru_idrss, usage->ru_isrss, usage->ru_minflt, usage->ru_majflt,
               usage->ru_nswap, usage->ru_inblock, usage->ru_oublock, usage->ru_msgsnd,
               usage->ru_msgrcv, usage->ru_nsignals, usage->ru_nvcsw);
        sleep(1);
    }
//    sleep(5);
    return 0;
}

//struct rusage {
//    struct timeval ru_utime; /* user CPU time used  output in ns*/
//    struct timeval ru_stime; /* system CPU time used output in ns*/
//    long ru_maxrss;        /* maximum resident set size */
//    long ru_ixrss;         /* integral shared memory size */
//    long ru_idrss;         /* integral unshared data size */
//    long ru_isrss;         /* integral unshared stack size */
//    long ru_minflt;        /* page reclaims (soft page faults) */
//    long ru_majflt;        /* page faults (hard page faults) */
//    long ru_nswap;         /* swaps */
//    long ru_inblock;       /* block input operations */
//    long ru_oublock;       /* block output operations */
//    long ru_msgsnd;        /* IPC messages sent */
//    long ru_msgrcv;        /* IPC messages received */
//    long ru_nsignals;      /* signals received */
//    long ru_nvcsw;         /* voluntary context switches */
//    long ru_nivcsw;        /* involuntary context switches */
//};

/*
Utime	Stime	maxrrs	ixrrs	idrss	isrrs	minflt	majflt	nswap	inblock	outblock	msgsnd	msgrcv	nsignals	nvcsw
386734	435076	1025288	    0	    0	    0	256230	     0	    0	      0	      0	         0	     0	       0	    0
469347	710037	2049136	    0	    0	    0	512232	     0	    0	      0	      0	         0	     0	       0	    0
553729	991095	3073192	    0	    0	    0	768233	     0	    0	      0	      0	         0	     0	       0	    0
660783	237466	4097248	    0	    0	    0	1024234	     0	    0	      0	      0	         0	     0	       0	    0
769974	483804	5121304	    0	    0	    0	1280235	     0	    0	      0	      0	         0	     0	       0	    0
881495	726928	6145360	    0	    0	    0	1536236	     0	    0	      0	      0	         0	     0	       0	    0
977945	991962	7169152	    0	    0	    0	1792237	     0	    0	      0	      0	         0	     0	       0	    0
69844	271917	8193208	    0	    0	    0	2048238	     0	    0	      0	      0	         0	     0	       0	    0
149299	590929	9217264	    0	    0	    0	2304239	     0	    0	      0	      0	         0	     0	       0	   10
292299	391283	10240052	    0	    0	    0	2560242	     2	    0	    288	      0	         0	     0	       0	  876
 */
