//
// Created by 1412 on 2025/11/26.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using TreeNode = treeHelper::TreeNode;

class Solution {
public:
    bool isValidBST(TreeNode* root) { return isValidBST(root, nullptr, nullptr); }

private:
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;
        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({2, 1, 3}, nullptr_value);
    assert(s.isValidBST(root) == true);
    treeHelper::free(root);

    root = treeHelper::build({5, 1, 4, nullptr_value, nullptr_value, 3, 6}, nullptr_value);
    assert(s.isValidBST(root) == false);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
