//
// Created by 1412 on 2025/10/16.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }

private:
    void dfs(vector<string>& res, string&& path, int l, int r) {
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
    vector<string> expected = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    assert(s.generateParenthesis(3) == expected);

    expected = {"()"};
    assert(s.generateParenthesis(1) == expected);
}

int main() {
    test();
    return 0;
}
