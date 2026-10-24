//
// Created by 1412 on 2025/10/12.
//

#include <algorithm>
#include <vector>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        std::vector<std::vector<int>> res;
        std::ranges::sort(nums);
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> expected = {
        {{-1, -1, 2}, {-1, 0, 1}}
    };
    CHECK(s.threeSum(nums) == expected);

    nums = {0, 1, 1};
    expected = {};
    CHECK(s.threeSum(nums) == expected);

    nums = {0, 0, 0};
    expected = {
        {0, 0, 0}
    };
    CHECK(s.threeSum(nums) == expected);
}

int main() {
    test();
    return 0;
}
