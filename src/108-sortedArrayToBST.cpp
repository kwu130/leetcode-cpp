//
// Created by 1412 on 2025/12/5.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);
        return root;
    }
};

void test() {
    Solution s;
    vector<int> nums = {-10, -3, 0, 5, 9};
    int nullptr_value = -1;
    TreeNode* expected = treeHelper::build({0, -10, 5, nullptr_value, -3, nullptr_value, 9}, nullptr_value);
    TreeNode* res = s.sortedArrayToBST(nums);
    assert(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);

    nums = {1, 3};
    expected = treeHelper::build({1, nullptr_value, 3}, nullptr_value);
    res = s.sortedArrayToBST(nums);
    assert(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
