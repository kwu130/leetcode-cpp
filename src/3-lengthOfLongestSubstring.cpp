//
// Created by 1412 on 2025/9/26.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int chs[128] = {0};
        int res = 0;
        for (int left = 0, right = 0; right < static_cast<int>(s.size()); right++) {
            auto c = static_cast<unsigned char>(s[right]);
            chs[c]++;
            while (chs[c] > 1) {
                auto lc = static_cast<unsigned char>(s[left]);
                chs[lc]--;
                left++;
            }
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.lengthOfLongestSubstring("abcabcbb") == 3);
    CHECK(s.lengthOfLongestSubstring("bbbbb") == 1);
    CHECK(s.lengthOfLongestSubstring("pwwkew") == 3);
}

int main() {
    test();
    return 0;
}
