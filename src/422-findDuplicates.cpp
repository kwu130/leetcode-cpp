//
// Created by 1412 on 2026/10/27.
//

#include <bits/stdc++.h>

#include "common.h"

using namespace std;

class Solution {
public:
    /*
     * 原地标记法：把数字 x 对应到下标 x - 1，用该位置的正负号记录 x 是否出现过。
     * 遍历时取 x = abs(nums[i])：
     * - 如果 nums[x - 1] > 0，说明第一次遇到 x，将该位置改为负数。
     * - 如果 nums[x - 1] < 0，说明之前遇到过 x，将 x 加入答案。
     */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> expected = {2, 3};
    vector<int> res = s.findDuplicates(nums);
    CHECK(compareHelper::equalIgnoreOrder(expected, res));

    nums = {1, 1, 2};
    expected = {1};
    res = s.findDuplicates(nums);
    CHECK(compareHelper::equalIgnoreOrder(expected, res));

    nums = {1};
    expected = {};
    res = s.findDuplicates(nums);
    CHECK(compareHelper::equalIgnoreOrder(expected, res));
}

int main() {
    test();
    return 0;
}
