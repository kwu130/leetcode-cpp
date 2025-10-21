//
// Created by 1412 on 2025/10/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int l = static_cast<int>(ranges::lower_bound(nums, target) - nums.begin());
        return l;
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    assert(s.searchInsert(nums, 5) == 2);
    assert(s.searchInsert(nums, 2) == 1);
    assert(s.searchInsert(nums, 7) == 4);
}

int main() {
    test();
    return 0;
}
