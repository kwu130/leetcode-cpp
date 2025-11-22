//
// Created by 1412 on 2025/10/27.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        ranges::sort(nums);  // sort nums firstly
        dfs(nums, vector<bool>(nums.size(), false), {}, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<bool>&& used, vector<int>&& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
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
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> expected = {
        {1, 1, 2},
        {1, 2, 1},
        {2, 1, 1}
    };
    assert(s.permuteUnique(nums) == expected);

    nums = {1, 2, 3};
    expected = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
    };
    assert(s.permuteUnique(nums) == expected);
}

int main() {
    test();
    return 0;
}
