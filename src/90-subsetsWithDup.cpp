//
// Created by 1412 on 2025/11/21.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        ranges::sort(nums);
        dfs(nums, 0, {}, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int index, vector<int>&& path, vector<vector<int>>& res) {
        res.emplace_back(path);
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            path.emplace_back(nums[i]);
            dfs(nums, i + 1, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> expected = {
        {},
        {1},
        {1, 2},
        {1, 2, 2},
        {2},
        {2, 2}
    };
    vector<vector<int>> res = s.subsetsWithDup(nums);
    assert(compareHelper::equalIgnoreOrder(res, expected));

    nums = {0};
    expected = {{}, {0}};
    res = s.subsetsWithDup(nums);
    assert(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
