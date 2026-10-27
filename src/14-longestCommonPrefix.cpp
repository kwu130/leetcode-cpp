//
// Created by 1412 on 2025/10/10.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        const int n = static_cast<int>(strs[0].size());
        for (int i = 0; i < n; i++) {
            for (const auto& str : strs) {
                if (i >= n || str[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

void test() {
    Solution s;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    CHECK(s.longestCommonPrefix(strs) == "fl");

    strs = {"dog", "racecar", "car"};
    CHECK(s.longestCommonPrefix(strs) == "");
}

int main() {
    test();
    return 0;
}
