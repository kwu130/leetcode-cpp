//
// Created by 1412 on 2025/10/29.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using namespace compareHelper;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        res.reserve(strs.size());
        unordered_map<string, vector<string>> mp;

        for (const auto& str : strs) {
            string tmp = str;
            ranges::sort(tmp);
            mp[tmp].push_back(str);
        }

        for (const auto& [_, value] : mp) {
            res.push_back(value);
        }

        return res;
    }
};

void test() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected = {
        {"bat"},
        {"nat", "tan"},
        {"ate", "eat", "tea"}
    };
    vector<vector<string>> res = s.groupAnagrams(strs);
    assert(compareHelper::equalIgnoreOrder(res, expected));

    strs = {""};
    expected = {{""}};
    res = s.groupAnagrams(strs);
    assert(compareHelper::equalIgnoreOrder(res, expected));

    strs = {"a"};
    expected = {{"a"}};
    res = s.groupAnagrams(strs);
    assert(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
