//
// Created by 1412 on 2025/11/30.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return symmetricTree(root->left, root->right);
    }

private:
    bool symmetricTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;
        return symmetricTree(root1->left, root2->right) && symmetricTree(root1->right, root2->left);
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({1, 2, 2, 3, 4, 4, 3}, nullptr_value);
    assert(s.isSymmetric(root) == true);
    treeHelper::free(root);

    root = treeHelper::build({1, 2, 2, nullptr_value, 3, nullptr_value, 3}, nullptr_value);
    assert(s.isSymmetric(root) == false);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
