//
// Created by 1412 on 2025/10/12.
//

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        std::ranges::sort(nums);
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                }
                if (std::abs(sum - target) < std::abs(res - target)) {
                    res = sum;
                }
                if (sum < target) {
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
    std::vector<int> nums = {-1, 2, 1, -4};
    CHECK(s.threeSumClosest(nums, 1) == 2);

    nums = {0, 0, 0};
    CHECK(s.threeSumClosest(nums, 1) == 0);
}

int main() {
    test();
    return 0;
}
