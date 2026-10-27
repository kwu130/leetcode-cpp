//
// Created by 1412 on 2025/10/27.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        dfs(nums, std::vector<bool>(nums.size(), false), {}, res);
        return res;
    }

private:
    void dfs(std::vector<int>& nums,
             std::vector<bool>&& used,
             std::vector<int>&& path,
             std::vector<std::vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            dfs(nums, std::move(used), std::move(path), res);
            path.pop_back();
            used[i] = false;
        }
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> expected = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
    };
    CHECK(s.permute(nums) == expected);

    nums = {0, 1};
    expected = {
        {0, 1},
        {1, 0}
    };
    CHECK(s.permute(nums) == expected);

    nums = {1};
    expected = {{1}};
    CHECK(s.permute(nums) == expected);
}

int main() {
    test();
    return 0;
}
