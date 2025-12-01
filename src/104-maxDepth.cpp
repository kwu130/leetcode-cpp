//
// Created by 1412 on 2025/12/1.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({3, 9, 20, nullptr_value, nullptr_value, 15, 7}, nullptr_value);
    assert(s.maxDepth(root) == 3);
    treeHelper::free(root);

    root = treeHelper::build({1, nullptr_value}, nullptr_value);
    assert(s.maxDepth(root) == 1);
    treeHelper::free(root);

    root = treeHelper::build({}, nullptr_value);
    assert(s.maxDepth(root) == 0);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
