//
// Created by 1412 on 2025/10/17.
//

#include <vector>

#include "common.h"


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (nums[res] != nums[i]) {
                nums[++res] = nums[i];
            }
        }
        return res + 1;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {1, 1, 2};
    std::vector<int> expected = {1, 2};
    CHECK(s.removeDuplicates(nums) == static_cast<int>(expected.size()));
    CHECK(std::vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    expected = {0, 1, 2, 3, 4};
    CHECK(s.removeDuplicates(nums) == static_cast<int>(expected.size()));
    CHECK(std::vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);
}

int main() {
    test();
    return 0;
}
