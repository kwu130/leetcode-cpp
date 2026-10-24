//
// Created by 1412 on 2025/11/13.
//

#include <utility>
#include <vector>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        dfs(nums, 0, {}, res);
        return res;
    }

private:
    void dfs(std::vector<int>& nums, int index, std::vector<int>&& path, std::vector<std::vector<int>>& res) {
        res.emplace_back(path);
        for (int i = index; i < static_cast<int>(nums.size()); i++) {
            path.emplace_back(nums[i]);
            dfs(nums, i + 1, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> expected = {
        {},
        {1},
        {2},
        {1, 2},
        {3},
        {1, 3},
        {2, 3},
        {1, 2, 3}
    };
    std::vector<std::vector<int>> res = s.subsets(nums);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    nums = {0};
    expected = {{}, {0}};
    res = s.subsets(nums);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
