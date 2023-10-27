#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Random {
public:
    static const double Epsilon;
    static void SetSeed();
    static double Double();
    static int Int(int max);
    static vector<int> Permutation(int n);
};

#endif
