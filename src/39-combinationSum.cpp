//
// Created by 1412 on 2025/10/23.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::ranges::sort(candidates);
        dfs(candidates, target, 0, {}, res);
        return res;
    }

private:
    void dfs(std::vector<int>& candidates,
             int target,
             int index,
             std::vector<int>&& path,
             std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.emplace_back(path);
            return;
        }
        for (int i = index; i < static_cast<int>(candidates.size()); i++) {
            if (candidates[i] > target) break;
            path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::vector<int> candidates = {2, 3, 6, 7};
    std::vector<std::vector<int>> expected = {
        {2, 2, 3},
        {7}
    };
    CHECK(s.combinationSum(candidates, 7) == expected);

    candidates = {2, 3, 5};
    expected = {
        {2, 2, 2, 2},
        {2, 3, 3},
        {3, 5}
    };
    CHECK(s.combinationSum(candidates, 8) == expected);

    candidates = {2};
    expected = {};
    CHECK(s.combinationSum(candidates, 1) == expected);
}

int main() {
    test();
    return 0;
}
