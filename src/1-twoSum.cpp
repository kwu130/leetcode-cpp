//
// Created by 1412 on 2025/9/23.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (hash.contains(target - nums[i])) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        throw;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> expected = {0, 1};
    std::vector<int> res = s.twoSum(nums, 9);
    CHECK(res == expected);

    nums = {3, 2, 4};
    expected = {1, 2};
    res = s.twoSum(nums, 6);
    CHECK(res == expected);

    nums = {3, 3};
    expected = {0, 1};
    res = s.twoSum(nums, 6);
    CHECK(res == expected);
}

int main() {
    test();
    return 0;
}
