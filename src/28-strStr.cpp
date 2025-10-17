//
// Created by 1412 on 2025/10/17.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int n = haystack.size(), m = needle.size();
        for (int i = 0; i < n - m + 1; i++) {
            if (haystack.substr(i, m) == needle) return i;
        }
        return -1;
    }
};

void test() {
    Solution s;
    assert(s.strStr("sadbutsad", "sad") == 0);
    assert(s.strStr("leetcode", "leeto") == -1);
}

int main() {
    test();
    return 0;
}
