//
// Created by 1412 on 2025/10/24.
//

#include <algorithm>
#include <utility>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
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
            if (i > index && candidates[i] == candidates[i - 1]) continue;  // 剪枝 重点理解这个 i>index 的作用
            path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    std::vector<std::vector<int>> expected = {
        {1, 1, 6},
        {1, 2, 5},
        {1, 7},
        {2, 6}
    };
    CHECK(s.combinationSum2(candidates, 8) == expected);

    candidates = {2, 5, 2, 1, 2};
    expected = {
        {1, 2, 2},
        {5}
    };
    CHECK(s.combinationSum2(candidates, 5) == expected);
}

int main() {
    test();
    return 0;
}
