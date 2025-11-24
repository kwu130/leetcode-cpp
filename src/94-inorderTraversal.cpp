//
// Created by 1412 on 2025/11/23.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

void test() {
    Solution s;
    int nullptr_val = -1;
    TreeNode* root = treeHelper::build({1, nullptr_val, 2, 3}, nullptr_val);
    vector<int> expected = {1, 3, 2};
    vector<int> res = s.inorderTraversal(root);
    assert(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({}, nullptr_val);
    expected = {};
    res = s.inorderTraversal(root);
    assert(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({1}, nullptr_val);
    expected = {1};
    res = s.inorderTraversal(root);
    assert(res == expected);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
