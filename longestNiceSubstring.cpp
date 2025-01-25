#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int isNice(string s, int start, int end) {
    for(int i = start; i < end; i++) {
        int found = 0;

        for(int j = i+1; j <= end; j++) {
            if (abs(s[i]-s[j]) == 32) {
                found = 1;
                break;
            }
        }

        if (!found) {
            return 0;
        }
    }

    return 1;
}

string longestNiceSubstring(string s) {
    string ans = "";
    int len = 0;
    for(int i = 0; i < s.size()-1; i++) {
        for(int j = i+1; j < s.size(); j++) {
            if (isNice(s, i, j) && len < (j-i+1)) {
                ans = "";
                for(int k = i; k <= j; k++) {
                    ans.push_back(s[k]);
                }
                len = j-i+1;
            }
        }
    }
    return ans;
}