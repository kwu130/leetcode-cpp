//
// Created by 1412 on 2025/10/21.
//

#include <algorithm>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        const int l = static_cast<int>(std::ranges::lower_bound(nums, target) - nums.begin());
        return l;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {1, 3, 5, 6};
    CHECK(s.searchInsert(nums, 5) == 2);
    CHECK(s.searchInsert(nums, 2) == 1);
    CHECK(s.searchInsert(nums, 7) == 4);
}

int main() {
    test();
    return 0;
}
