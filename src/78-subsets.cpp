//
// Created by 1412 on 2025/11/13.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, {}, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, int index, vector<int>&& path, vector<vector<int>>& res) {
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
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> expected = {
        {},
        {1},
        {2},
        {1, 2},
        {3},
        {1, 3},
        {2, 3},
        {1, 2, 3}
    };
    vector<vector<int>> res = s.subsets(nums);
    assert(compareHelper::equalIgnoreOrder(res, expected));

    nums = {0};
    expected = {{}, {0}};
    res = s.subsets(nums);
    assert(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
