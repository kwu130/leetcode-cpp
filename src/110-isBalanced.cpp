//
// Created by 1412 on 2025/12/7.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({3, 9, 20, nullptr_value, nullptr_value, 15, 7}, nullptr_value);
    assert(s.isBalanced(root) == true);
    treeHelper::free(root);

    root = treeHelper::build({1, 2, 2, 3, 3, nullptr_value, nullptr_value, 4, 4}, nullptr_value);
    assert(s.isBalanced(root) == false);
    treeHelper::free(root);

    root = treeHelper::build({}, nullptr_value);
    assert(s.isBalanced(root) == true);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
