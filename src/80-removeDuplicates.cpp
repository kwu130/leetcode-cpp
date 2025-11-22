//
// Created by 1412 on 2025/11/16.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (const auto& num : nums) {
            if (i < 2 || num != nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> expected = {1, 1, 2, 2, 3};
    assert(s.removeDuplicates(nums) == static_cast<int>(expected.size()));
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);

    nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    expected = {0, 0, 1, 1, 2, 3, 3};
    assert(s.removeDuplicates(nums) == static_cast<int>(expected.size()));
    assert(vector<int>(nums.begin(), nums.begin() + expected.size()) == expected);
}

int main() {
    test();
    return 0;
}
