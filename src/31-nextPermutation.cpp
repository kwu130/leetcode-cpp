//
// Created by 1412 on 2025/10/19.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // find first nums[i] < nums[i + 1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        // find first nums[j] > nums[i]
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            // swap
            swap(nums[i], nums[j]);
        }
        // reverse nums[i + 1, nums.size() - 1]
        reverse(nums.begin() + i + 1, nums.end());
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<int> expected = {1, 3, 2};
    s.nextPermutation(nums);
    assert(nums == expected);

    nums = {3, 2, 1};
    expected = {1, 2, 3};
    s.nextPermutation(nums);
    assert(nums == expected);

    nums = {1, 1, 5};
    expected = {1, 5, 1};
    s.nextPermutation(nums);
    assert(nums == expected);
}

int main() {
    test();
    return 0;
}
