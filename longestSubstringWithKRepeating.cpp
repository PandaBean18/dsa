#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Problem: given a string s and an int k, find length of the longest substring such that each character repeats atleast k times

// Solution: iterate over the string and find number of occurances of each char. if occurance of each char >= k, then return length
// of the string. If not, divide the string on these characters, then find the length of each substring and return the max

int longestSubstring(string s, int k) {
    if (s.size() < k) {
        return 0;
    }

    unordered_map<char, int> m;

    for(int i = 0; i < s.size(); i++) {
        m[s[i]] += 1;
    }

    int found = 0;

    for(unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second < k) {
            found = 1;
            break;
        }
    }

    if (!found) {
        return s.size();
    }

    int max = 0;
    string str = "";

    for(int i = 0; i < s.size(); i++) {
        if (m[s[i]] < k && !str.empty()) {
            int a = longestSubstring(str, k);
            if (a > max) {
                max = a;
            }
            str = "";
        } else if (m[s[i]] >= k) {
            str.push_back(s[i]);
        }
    }
    int a = longestSubstring(str, k);
    if (a > max) {
        max = a;
    }
    return max;

}