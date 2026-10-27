//
// Created by 1412 on 2025/10/17.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int res = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != val) {
                nums[++res] = nums[i];
            }
        }
        return res + 1;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {3, 2, 2, 3};
    std::vector<int> expected = {2, 2};
    CHECK(s.removeElement(nums, 3) == static_cast<int>(expected.size()));
    CHECK(std::vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    expected = {0, 1, 3, 0, 4};
    CHECK(s.removeElement(nums, 2) == static_cast<int>(expected.size()));
    CHECK(std::vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {};
    expected = {};
    CHECK(s.removeElement(nums, 1) == static_cast<int>(expected.size()));
    CHECK(std::vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);
}

int main() {
    test();
    return 0;
}
