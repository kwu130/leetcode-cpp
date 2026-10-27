//
// Created by 1412 on 2025/11/13.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        dfs(res, {}, 1, n, k);
        return res;
    }

private:
    void dfs(std::vector<std::vector<int>>& res, std::vector<int>&& path, int start, int n, int k) {
        if (static_cast<int>(path.size()) == k) {
            res.emplace_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(res, std::move(path), i + 1, n, k);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::vector<std::vector<int>> expected = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4}
    };
    std::vector<std::vector<int>> res = s.combine(4, 2);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    expected = {{1}};
    res = s.combine(1, 1);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
