//
// Created by 1412 on 2026/11/2.
//

#include <bits/stdc++.h>

#include "common.h"

using namespace std;

class Solution {
public:
    // 核心结论：如果字符串 s 可以由某个子串重复构成，那么 (s + s) 去掉首尾各一个字符后，一定仍然包含
    // s（充分必要条件）。
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, t.length() - 2).find(s) != string::npos;
    }
};

void test() {
    Solution s;
    CHECK(s.repeatedSubstringPattern("abab") == true);
    CHECK(s.repeatedSubstringPattern("aba") == false);
    CHECK(s.repeatedSubstringPattern("abcabcabcabc") == true);
}

int main() {
    test();
    return 0;
}
