//
// Created by 1412 on 2025/12/7.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({3, 9, 20, nullptr_value, nullptr_value, 15, 7}, nullptr_value);
    assert(s.minDepth(root) == 2);
    treeHelper::free(root);

    root =
        treeHelper::build({2, nullptr_value, 3, nullptr_value, 4, nullptr_value, 5, nullptr_value, 6}, nullptr_value);
    assert(s.minDepth(root) == 5);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
