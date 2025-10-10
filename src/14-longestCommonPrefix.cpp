//
// Created by 1412 on 2025/10/10.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); i++) {
            for (const auto& str : strs) {
                if (i >= str.size() || str[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

void test() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    assert(s.longestCommonPrefix(strs) == "fl");
    strs = {"dog", "racecar", "car"};
    assert(s.longestCommonPrefix(strs) == "");
}

int main() {
    test();
    return 0;
}
