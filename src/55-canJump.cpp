//
// Created by 1412 on 2025/11/3.
//

#include <algorithm>
#include <vector>

#include "common.h"


class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int reach = 0;
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n && i <= reach; ++i) {
            reach = std::max(reach, i + nums[i]);
            if (reach >= n - 1) return true;
        }
        return false;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    CHECK(s.canJump(nums) == true);

    nums = {3, 2, 1, 0, 4};
    CHECK(s.canJump(nums) == false);
}

int main() {
    test();
    return 0;
}
