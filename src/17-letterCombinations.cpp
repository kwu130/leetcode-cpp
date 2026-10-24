//
// Created by 1412 on 2025/10/13.
//

#include <string>
#include <utility>
#include <vector>

#include "common.h"


class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }
        std::vector<std::string> res;
        dfs(digits, 0, "", res);
        return res;
    }

private:
    const std::vector<std::string> m{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(const std::string& digits, int index, std::string&& path, std::vector<std::string>& res) {
        if (index == static_cast<int>(digits.size())) {
            res.push_back(path);
            return;
        }
        for (const auto& c : m[digits[index] - '0']) {
            path.push_back(c);
            dfs(digits, index + 1, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::string digits = "23";
    std::vector<std::string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    CHECK(s.letterCombinations(digits) == expected);

    digits = "";
    expected = {};
    CHECK(s.letterCombinations(digits) == expected);

    digits = "2";
    expected = {"a", "b", "c"};
    CHECK(s.letterCombinations(digits) == expected);
}

int main() {
    test();
    return 0;
}
