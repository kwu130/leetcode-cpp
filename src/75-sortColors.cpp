//
// Created by 1412 on 2025/11/12.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; j <= k;) {
            if (nums[j] == 0) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] == 1) {
                j++;
            } else if (nums[j] == 2) {
                swap(nums[j], nums[k--]);
            }
        }
    }
};

void test() {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> expected = {0, 0, 1, 1, 2, 2};
    s.sortColors(nums);
    assert(nums == expected);

    nums = {2, 0, 1};
    expected = {0, 1, 2};
    s.sortColors(nums);
    assert(nums == expected);
}

int main() {
    test();
    return 0;
}
