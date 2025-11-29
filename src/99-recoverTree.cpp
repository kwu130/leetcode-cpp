//
// Created by 1412 on 2025/11/29.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using TreeNode = treeHelper::TreeNode;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        inorder(root, first, second);
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second) {
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (prev != nullptr && prev->val > root->val) {
                second = root;
                if (first == nullptr) {
                    first = prev;
                }
            }
            prev = root;
            root = root->right;
        }
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({1, 3, nullptr_value, nullptr_value, 2}, nullptr_value);
    TreeNode* expected = treeHelper::build({3, 1, nullptr_value, nullptr_value, 2}, nullptr_value);
    s.recoverTree(root);
    assert(treeHelper::equal(root, expected));
    treeHelper::free(root);
    treeHelper::free(expected);

    root = treeHelper::build({3, 1, 4, nullptr_value, nullptr_value, 2}, nullptr_value);
    expected = treeHelper::build({2, 1, 4, nullptr_value, nullptr_value, 3}, nullptr_value);
    s.recoverTree(root);
    assert(treeHelper::equal(root, expected));
    treeHelper::free(root);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
