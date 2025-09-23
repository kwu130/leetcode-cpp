//
// Created by 1412 on 2025/9/23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.contains(target - nums[i])) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        throw;
    }
};

void test() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> expected = {0, 1};
    vector<int> res = s.twoSum(nums, 9);
    assert(res == expected);
    nums = {3, 2, 4};
    expected = {1, 2};
    res = s.twoSum(nums, 6);
    assert(res == expected);
    nums = {3, 3};
    expected = {0, 1};
    res = s.twoSum(nums, 6);
    assert(res == expected);
}

int main() {
    test();
    return 0;
}
