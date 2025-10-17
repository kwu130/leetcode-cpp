//
// Created by 1412 on 2025/10/17.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[++res] = nums[i];
            }
        }
        return res + 1;
    }
};

void test() {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    vector<int> expected = {2, 2};
    assert(s.removeElement(nums, 3) == expected.size());
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    expected = {0, 1, 3, 0, 4};
    assert(s.removeElement(nums, 2) == expected.size());
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {};
    expected = {};
    assert(s.removeElement(nums, 1) == expected.size());
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);
}

int main() {
    test();
    return 0;
}
