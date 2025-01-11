#include <iostream>
#include <stack>

using namespace std;

// problem statement: given two parameters, a string s and int k, removed k characters from s such that the resulting string 
// is the smallest possible integer value

// solution: let n be (len(s)-k) that is the length of final string. Now, the most significant digit of the final string will be
// the smallest digit in s[0..(len(s)-n+0)]
// the second most signinficant digit will be the smallest in s[(j+1)..(len(s)-n+1)] where j is the index of most significant digit. and
// so on

// 4 3 8 9 2 7 -> 3 8 2 7 
// counter = 5
// slotsLeft = 1
// digitsLeft = n-(counter+1) = 0
// currentChangableIndex = (n-k)-(digitsLeft+1) ? k-(digitsLeft-1) >= 0 : 0 = 3


// O(n^2) solution:
// char* findLexologicallySmallestString(char* s, int n, int k) {
//     char* finalString = (char*)malloc((n-k)*sizeof(char));

//     int i = 0;
//     int j = 0;
//     while (i < (n-k)) {
//         char smallest = s[j];
//         int smallestIndex = j;
//         for(j; j < (k+i+1); j++) {
//             if (s[j] < smallest) {
//                 smallest = s[j];
//                 smallestIndex = j;
//             }
//         }
//         finalString[i] = smallest;
//         i++;
//         j = smallestIndex+1;
//     } 
//     return finalString;
// }

// n = 6
// k = 3
// 4 3 8 9 2 7 -> 4 _ _
// counter = 1;
// slotsLeft = 2;
// digitsLeft = 5;
// currentChangableIndex = 0

char* findLexologicallySmallestString(char* s, int n, int k) {
    stack<char> stk;
    char* finalString = (char*)malloc((n-k)*sizeof(char));
    int i = 0;
    int count = 0;

    while (i < n) {
        if (stk.empty()) {
            stk.push(s[i]);
            count++;
        } else {
            if (stk.top() > s[i]) {
                while (!stk.empty() && ((n-i) > (n-k-count)) && (stk.top() > s[i]) && (count >= 0)) {
                    stk.pop();
                    count--;
                }
                stk.push(s[i]);
                count++;
            } else {
                if (count < n-k) {
                    stk.push(s[i]);
                    count++;
                }
            }
        }
        i++;
    }

    int j = 0;

    while (!stk.empty()) {
        finalString[n-k-1-j] = stk.top();
        j++;
        stk.pop();
    }

    return finalString;
}


int main(int argc, char* argv[]) {
    char* s = argv[1];
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);

    char* finalString = findLexologicallySmallestString(s, n, k);
    cout << finalString << endl;
    return 0;
}