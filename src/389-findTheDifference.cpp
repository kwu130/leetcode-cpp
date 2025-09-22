//
// Created by 1412 on 2025/9/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ch_cnt[26] = {0};
        for (const char ch : s) {
            ch_cnt[ch - 'a']++;
        }
        for (const char ch : t) {
            if (--ch_cnt[ch - 'a'] < 0) {
                return ch;
            }
        }
        throw;
    }
};

void test() {
    Solution s;
    assert(s.findTheDifference("abcd", "abcde") == 'e');
    assert(s.findTheDifference("", "y") == 'y');
    assert(s.findTheDifference("a", "aa") == 'a');
}

int main() {
    test();
    return 0;
}
