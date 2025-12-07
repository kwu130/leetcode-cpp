//
// Created by 1412 on 2025/12/7.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build(
        {5, 4, 8, 11, nullptr_value, 13, 4, 7, 2, nullptr_value, nullptr_value, nullptr_value, 1}, nullptr_value);
    assert(s.hasPathSum(root, 22) == true);
    treeHelper::free(root);

    root = treeHelper::build({1, 2, 3}, nullptr_value);
    assert(s.hasPathSum(root, 5) == false);
    treeHelper::free(root);

    root = treeHelper::build({}, nullptr_value);
    assert(s.hasPathSum(root, 0) == false);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
