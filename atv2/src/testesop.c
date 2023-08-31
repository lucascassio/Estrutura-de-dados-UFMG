#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#include "../include/testes.h"

long long int FatItr(int n) {
    long long int f = 1;
    while (n > 0) {
        f *= n;
        n--;
    }
    return f;
}

long long int FatRec(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * FatRec(n - 1);
    }
}

long long int FibItr(int n) {
    int fn1 = 1, fn2 = 1;
    int fn, i;
    if (n < 3) return 1;
    for (i = 3; i <= n; i++) {
        fn = fn2 + fn1;
        fn2 = fn1;
        fn1 = fn; 
    } 
    return fn; 
}


long long int FibRec(int n) {
    if(n < 3) {
        return 1;
    } else {
        return FibRec(n - 1) + FibRec(n - 2);
    }
}

