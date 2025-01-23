#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// problem: given an array of size n, find the element that occurs in the array more than n/2 times

// using unordered map: o(n + k) where k is the number of elements.

// int majorityElement(vector<int>& arr) {
//     unordered_map<int, int> m;

//     for(int i = 0; i < arr.size(); i++) {
//         m[arr[i]] += 1;
//     }

//     for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
//         if (it->second > (arr.size() / 2)) {
//             return it->first;
//         }
//     }

//     return -1;
// }

// since we are finding majority, we can use moore's voting algorithm
// moore voting algorithm works as such:
// for every x in arr, if count == 0; max = x and count++. else if count != 0, if x == max, count++ else count--; 
// O(n) time complexity, O(1) space complexity

int majorityElement(vector<int>& arr) {
    int m, count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (count == 0) {
            m = arr[i];
            count++;
        } else if (m == arr[i]) {
            count++;
        } else if (m != arr[i]) {
            count--;
        }
    }

    return m;
}