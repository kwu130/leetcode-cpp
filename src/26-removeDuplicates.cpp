//
// Created by 1412 on 2025/10/17.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            if (nums[res] != nums[i]) {
                nums[++res] = nums[i];
            }
        }
        return res + 1;
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<int> expected = {1, 2};
    assert(s.removeDuplicates(nums) == static_cast<int>(expected.size()));
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    expected = {0, 1, 2, 3, 4};
    assert(s.removeDuplicates(nums) == static_cast<int>(expected.size()));
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);
}

int main() {
    test();
    return 0;
}
