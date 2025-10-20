//
// Created by 1412 on 2025/10/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == target) return m;
            if (nums[l] <= nums[m]) {                         // nums[l...m] is sorted
                if (nums[l] <= target && target < nums[m]) {  // target in [l...m]
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {                                          // nums[m...r] is sorted
                if (nums[m] < target && target <= nums[r]) {  // target in [m...r]
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};

void test() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    assert(s.search(nums, 0) == 4);
    assert(s.search(nums, 3) == -1);

    nums = {1};
    assert(s.search(nums, 0) == -1);
}

int main() {
    test();
    return 0;
}
