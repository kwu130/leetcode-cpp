//
// Created by 1412 on 2025/10/29.
//

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.h"


using namespace compareHelper;

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        res.reserve(strs.size());
        std::unordered_map<std::string, std::vector<std::string>> mp;

        for (const auto& str : strs) {
            std::string tmp = str;
            std::ranges::sort(tmp);
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
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> expected = {
        {"bat"},
        {"nat", "tan"},
        {"ate", "eat", "tea"}
    };
    std::vector<std::vector<std::string>> res = s.groupAnagrams(strs);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    strs = {""};
    expected = {{""}};
    res = s.groupAnagrams(strs);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    strs = {"a"};
    expected = {{"a"}};
    res = s.groupAnagrams(strs);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
