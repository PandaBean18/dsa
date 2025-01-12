#include <iostream>

using namespace std; 

// problem: Given a value n, find its integral cube root x, where integral value x is the largest integer such that x^3 <= n

// Solution 1: Starting from 0 till n, check cube of all numbers and if i*i*i > n, return n-1. This has O(n) time complexity
// Solution 2: Starting from 1, while i*i*i <= n, keep doubling i (i = i*2). The point at which i*i*i > n, now we know that the x
// lies between (i/2) and (i-1), both inclusive. at this point we can use binary search to narrow down to x. Should have time complexity
// of O(log(n))

int findIntegralCubeRoot(int n) {
    int i = 1;
    int count = 0;
    if (n == 1) {
        return 1;
    }

    while (i <= n/2) {
        int product = i*i*i;

        if (product == n) {
            return i;
        } else if (product > n) {
            int s = (i/2), e = i-1;
            int j = (s+e)/2;

            while (s != e) {
                int p = j*j*j;

                if ((p <= n) && (p + 3*(j*j) + 3*j + 1) > n) {
                    cout << count << endl;
                    return j;
                } else if (p < n) {
                    s = j+1;
                } else {
                    e = j-1;
                }
                j = (s+e)/2;
                count++;
            }
            int p = j*j*j;

            if ((p <= n) && (p + 3*(j*j) + 3*j + 1) > n) {
                cout << count << endl;
                return j;
            } 
            
        } else  {
            i = i*2;
        }
        count++;
    }
    
    return -1;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    cout << findIntegralCubeRoot(n) << endl;

    return 0;
}