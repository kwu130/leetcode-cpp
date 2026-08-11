//
// Created by 1412 on 2025/10/16.
//

#include <string>
#include <utility>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        dfs(res, "", n, n);
        return res;
    }

private:
    void dfs(std::vector<std::string>& res, std::string&& path, int l, int r) {
        if (l == 0 && r == 0) {
            res.push_back(path);
            return;
        }
        if (l > 0) {
            path.push_back('(');
            dfs(res, std::move(path), l - 1, r);
            path.pop_back();
        }
        if (l < r) {
            path.push_back(')');
            dfs(res, std::move(path), l, r - 1);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::vector<std::string> expected = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    CHECK(s.generateParenthesis(3) == expected);

    expected = {"()"};
    CHECK(s.generateParenthesis(1) == expected);
}

int main() {
    test();
    return 0;
}
