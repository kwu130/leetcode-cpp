//
// Created by 1412 on 2025/10/13.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res;
        dfs(digits, 0, "", res);
        return res;
    }

private:
    const vector<string> m{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(const string& digits, int index, string&& path, vector<string>& res) {
        if (index == digits.size()) {
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
    string digits = "23";
    vector<string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(s.letterCombinations(digits) == expected);
    digits = "";
    expected = {};
    assert(s.letterCombinations(digits) == expected);
    digits = "2";
    expected = {"a", "b", "c"};
}

int main() {
    test();
    return 0;
}
