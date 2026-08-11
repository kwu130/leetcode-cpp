//
// Created by 1412 on 2025/10/26.
//

#include <algorithm>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    int jump(std::vector<int>& nums) {
        int res = 0;
        int end = 0;
        int farthest = 0;
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                res++;
                break;
            }
            if (i == end) {
                res++;
                end = farthest;
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    CHECK(s.jump(nums) == 2);

    nums = {2, 3, 0, 1, 4};
    CHECK(s.jump(nums) == 2);

    nums = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    CHECK(s.jump(nums) == 2);
}

int main() {
    test();
    return 0;
}
