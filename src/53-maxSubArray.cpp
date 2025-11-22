//
// Created by 1412 on 2025/10/30.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            sum += nums[i];
            res = max(res, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(s.maxSubArray(nums) == 6);

    nums = {1};
    assert(s.maxSubArray(nums) == 1);

    nums = {5, 4, -1, 7, 8};
    assert(s.maxSubArray(nums) == 23);
}

int main() {
    test();
    return 0;
}
