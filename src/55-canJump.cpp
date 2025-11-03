//
// Created by 1412 on 2025/11/3.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size() && i <= reach; ++i) {
            reach = max(reach, i + nums[i]);
            if (reach >= nums.size() - 1) return true;
        }
        return false;
    }
};

void test() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    assert(s.canJump(nums) == true);

    nums = {3, 2, 1, 0, 4};
    assert(s.canJump(nums) == false);
}

int main() {
    test();
    return 0;
}
