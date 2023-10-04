#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>

#include "../include/testes.h"

/*double computeSin() {
    double result = 0.0;
    for (int i = 0; i < 1500000; i++) {
        result += sin(0);
    }
    return result;
}*/

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


long long FibRec(int n) {
    if (n <= 1) {
        return n;
    } else {
        return FibRec(n - 1) + FibRec(n - 2);
    }
}