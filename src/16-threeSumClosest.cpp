//
// Created by 1412 on 2025/10/12.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        ranges::sort(nums);
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return sum;
                }
                if (abs(sum - target) < abs(res - target)) {
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
    vector<int> nums = {-1, 2, 1, -4};
    assert(s.threeSumClosest(nums, 1) == 2);
    nums = {0, 0, 0};
    assert(s.threeSumClosest(nums, 1) == 0);
}

int main() {
    test();
    return 0;
}
