//
// Created by 1412 on 2025/9/22.
//

#include <string>

#include "test_helper.h"


class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
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
    CHECK(s.findTheDifference("abcd", "abcde") == 'e');
    CHECK(s.findTheDifference("", "y") == 'y');
    CHECK(s.findTheDifference("a", "aa") == 'a');
}

int main() {
    test();
    return 0;
}
