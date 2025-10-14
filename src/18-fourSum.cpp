//
// Created by 1412 on 2025/10/14.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ranges::sort(nums);
        return kSum(nums, 4, 0, target);
    }

private:
    vector<vector<int>> kSum(vector<int>& nums, int k, int start, long target) {
        if (nums.size() < k || k < 2) return {};
        vector<vector<int>> res;
        if (k == 2) {
            int left = start, right = nums.size() - 1;
            while (left < right) {
                long sum = nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        } else {
            for (int i = start; i < nums.size(); i++) {
                auto sub = kSum(nums, k - 1, i + 1, target - nums[i]);
                for (auto& v : sub) {
                    v.push_back(nums[i]);
                    res.push_back(v);
                }
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
            }
        }

        return res;
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> expected = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    assert(compareHelper::equalIgnoreOrder(s.fourSum(nums, 0), expected));

    nums = {2, 2, 2, 2, 2};
    expected = {{2, 2, 2, 2}};
    assert(compareHelper::equalIgnoreOrder(s.fourSum(nums, 8), expected));

    nums = {-2, -1, -1, 1, 1, 2, 2};
    expected = {{1, 2, -1, -2}, {1, 1, -1, -1}};
    assert(compareHelper::equalIgnoreOrder(s.fourSum(nums, 0), expected));

    nums = {1000000000, 1000000000, 1000000000, 1000000000};
    expected = {};
    assert(compareHelper::equalIgnoreOrder(s.fourSum(nums, -294967296), expected));
}

int main() {
    test();
    return 0;
}
