#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

#include "../include/testes.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    struct timespec t1, t2;
    struct rusage sU, eU;
    long int seconds;
    long int nanoseconds;

    // Medir o tempo para o Fatorial Iterativo
    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &sU);
    long long result1 = FatItr(n);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    getrusage(RUSAGE_SELF, &eU);

    if (t2.tv_nsec < t1.tv_nsec) {
        nanoseconds = 1000000000 + t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec - 1;
    } else {
        nanoseconds = t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec;
    }

    printf("\n");
    printf("Resultado Fatorial Iterativo para %d: %lld\n", n, result1);
    printf("Tempo de utilização usuário (Fatorial Iterativo): %ld segundos e %ld nanoseconds\n", eU.ru_utime.tv_sec - sU.ru_utime.tv_sec, eU.ru_utime.tv_usec - sU.ru_utime.tv_usec);
    printf("Tempo de utilização sistema (Fatorial Iterativo): %ld segundos e %ld nanoseconds\n", eU.ru_stime.tv_sec - sU.ru_stime.tv_sec, eU.ru_stime.tv_usec - sU.ru_stime.tv_usec);
    printf("Tempo de execução (Fatorial Iterativo): %ld segundos e %ld nanoseconds\n", seconds, nanoseconds);

    printf("\n");

    // Medir o tempo para o Fatorial Recursivo
    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &sU);
    long long result2 = FatRec(n);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    getrusage(RUSAGE_SELF, &eU);

    if (t2.tv_nsec < t1.tv_nsec) {
        nanoseconds = 1000000000 + t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec - 1;
    } else {
        nanoseconds = t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec;
    }

    printf("Resultado Fatorial Recursivo para %d: %lld\n", n, result2);
    printf("Tempo de utilização usuário (Fatorial Recursivo): %ld segundos e %ld nanoseconds\n", eU.ru_utime.tv_sec - sU.ru_utime.tv_sec, eU.ru_utime.tv_usec - sU.ru_utime.tv_usec);
    printf("Tempo de utilização sistema (Fatorial Recursivo): %ld segundos e %ld nanoseconds\n", eU.ru_stime.tv_sec - sU.ru_stime.tv_sec, eU.ru_stime.tv_usec - sU.ru_stime.tv_usec);
    printf("Tempo de execução (Fatorial Recursivo): %ld segundos e %ld nanoseconds\n", seconds, nanoseconds);

    printf("\n");
    printf("--------------------------------------------------");
    printf("\n");
    printf("\n");

    // Medir o tempo para o Fibonacci Iterativo
    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &sU);
    long long result3 = FibItr(n);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    getrusage(RUSAGE_SELF, &eU);

    if (t2.tv_nsec < t1.tv_nsec) {
        nanoseconds = 1000000000 + t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec - 1;
    } else {
        nanoseconds = t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec;
    }

    printf("Resultado Fibonacci Iterativo para %d: %lld\n", n, result3);
    printf("Tempo de utilização usuário (Fibonacci Iterativo): %ld segundos e %ld nanoseconds\n", eU.ru_utime.tv_sec - sU.ru_utime.tv_sec, eU.ru_utime.tv_usec - sU.ru_utime.tv_usec);
    printf("Tempo de utilização sistema (Fibonacci Iterativo): %ld segundos e %ld nanoseconds\n", eU.ru_stime.tv_sec - sU.ru_utime.tv_sec, eU.ru_stime.tv_usec - sU.ru_stime.tv_usec);
    printf("Tempo de execução (Fibonacci Iterativo): %ld segundos e %ld nanoseconds\n", seconds, nanoseconds);

    printf("\n");

    // Medir o tempo para o Fibonacci Recursivo
    clock_gettime(CLOCK_MONOTONIC, &t1);
    getrusage(RUSAGE_SELF, &sU);
    long long result4 = FibRec(n);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    getrusage(RUSAGE_SELF, &eU);

    if (t2.tv_nsec < t1.tv_nsec) {
        nanoseconds = 1000000000 + t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec - 1;
    } else {
        nanoseconds = t2.tv_nsec - t1.tv_nsec;
        seconds = t2.tv_sec - t1.tv_sec;
    }

    printf("Resultado Fibonacci Recursivo para %d: %lld\n", n, result4);
    printf("Tempo de utilização usuário (Fibonacci Recursivo): %ld segundos e %ld nanoseconds\n", eU.ru_utime.tv_sec - sU.ru_utime.tv_sec, eU.ru_utime.tv_usec - sU.ru_utime.tv_usec);
    printf("Tempo de utilização sistema (Fibonacci Recursivo): %ld segundos e %ld nanoseconds\n", eU.ru_stime.tv_sec - sU.ru_stime.tv_sec, eU.ru_stime.tv_usec - sU.ru_stime.tv_usec);
    printf("Tempo de execução (Fibonacci Recursivo): %ld segundos e %ld nanoseconds\n", seconds, nanoseconds);

    return 0;
}
