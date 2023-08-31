#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../include/testes.h"

typedef long long (*FunctionType)(int);

void measureExecutionTime(FunctionType func, int n, const char* funcName) {
    struct timespec t1, t2;
    struct rusage sU, eU;
    long int seconds;
    long int nanoseconds;

    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &sU);

    long long result = func(n);

    clock_gettime(CLOCK_MONOTONIC, &t2);
    getrusage(RUSAGE_SELF, &eU);

    if (t2.tv_nsec < t1.tv_nsec){
    // ajuste necessario, utilizando um segundo de tv_sec
    nanoseconds = 1000000000+t2.tv_nsec-t1.tv_nsec;
    seconds = t2.tv_sec-t1.tv_sec-1;
    } else {
    // nao e necessario ajuste
    nanoseconds = t2.tv_nsec-t1.tv_nsec;
    seconds = t2.tv_sec-t1.tv_sec;
    }


    printf("\n");
    printf("Resultado %s para %d: %lld\n", funcName, n, result);
    printf("Tempo de utilizacao usuario: %ld segundos e %d nanoseconds\n", eU.ru_utime.tv_sec - sU.ru_utime.tv_sec, eU.ru_utime.tv_usec - sU.ru_utime.tv_usec);
    printf("Tempo de utilizacao sistema: %ld segundos e %d nanoseconds\n", eU.ru_stime.tv_sec - sU.ru_stime.tv_sec, eU.ru_stime.tv_usec - sU.ru_stime.tv_usec);
    printf("Tempo de execução: %ld segundos e %ld nanoseconds\n", seconds, nanoseconds);

}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    measureExecutionTime(FatItr, n, "Fatorial Iterativo");
    measureExecutionTime(FatRec, n, "Fatorial Recursivo");
    printf("\n");
    printf("--------------------------------------------------");
    printf("\n");
    measureExecutionTime(FibItr, n, "Fibonacci Iterativo");
    measureExecutionTime(FibRec, n, "Fibonacci Recursivo");

    return 0;
}
