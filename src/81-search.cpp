//
// Created by 1412 on 2025/11/16.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == target) return true;
            if (nums[l] == nums[r]) {
                ++l;
                continue;
            }
            if (nums[l] <= nums[m]) {  // nums[l..m] are sorted
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[r]) {  // nums[m..r] are sorted
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};

void test() {
    Solution s;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    assert(s.search(nums, 0) == true);

    nums = {2, 5, 6, 0, 0, 1, 2};
    assert(s.search(nums, 3) == false);
}

int main() {
    test();
    return 0;
}
