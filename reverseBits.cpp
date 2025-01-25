#include <iostream>
#include <vector>

using namespace std;

// problem: given an unsigned integer n, return the integer represented by the reverse of the 32bit binary representation of the number

// solution 1: convert the number to binary by dividing by 2 and store it in an array of size 32, then create the result from it

// solution 2: use bit manipulation to write the bit data in reverse order.

// uint32_t reverseBits(uint32_t n) {
//     uint32_t ans = 0;
//     int arr[32] = {0};
    
//     for (int i = 31; i >= 0; i--) {
//         if (n % 2) {
//             arr[i] = 1;
//         }
//         n = n / 2;
        
//         if (!n) {
//             break;
//         }
//     }
    
//     uint32_t prev = 0;
    
//     for (int i = 0; i < 32; i++) {
//         if (!prev) {
//             prev = 1;
//         } else {
//             prev *= 2;
//         }
        
//         if (arr[i]) {
//             ans += prev;
//         }
//     }
    
//     return ans;
// }

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    int i = 0;

    while (i < 32) {
        ans = ans | (n & 1);
        ans = ans << 1;
        n = n >> 1;
        i++;
    }
    return ans;
}