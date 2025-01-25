#include <iostream>

using namespace std;

// problem: given a 32 bit integer, find number of set bits in its binary representation

int hammingWeight(int n) {
    int count = 0;

    while (n) {
        if (n & 1) {
            count++;
        }

        n = n >> 1;
    }

    return count;
}