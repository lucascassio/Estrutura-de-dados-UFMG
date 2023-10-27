#ifndef UTILS_HPP
#define UTILS_HPP

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Utils{
    public:
        static int BinarySearch(vector<int> v, int k);
    private:
        static int BinarySearchRecursion(vector<int> v, int k, int l, int r);
};

#endif