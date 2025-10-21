//
// Created by 1412 on 2025/10/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int l = static_cast<int>(ranges::lower_bound(nums, target) - nums.begin());  // find first >= target
        if (l == nums.size() || nums[l] != target) return {-1, -1};
        const int r = static_cast<int>(ranges::upper_bound(nums, target) - nums.begin() - 1);  // find first > target
        return {l, r};
    }
};

void test() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> expected = {3, 4};
    assert(s.searchRange(nums, 8) == expected);

    expected = {-1, -1};
    assert(s.searchRange(nums, 6) == expected);

    nums = {};
    expected = {-1, -1};
    assert(s.searchRange(nums, 0) == expected);
}

int main() {
    test();
    return 0;
}
