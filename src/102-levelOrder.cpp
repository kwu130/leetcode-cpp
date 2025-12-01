//
// Created by 1412 on 2025/12/1.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t n = q.size();
            vector<int> level;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root = treeHelper::build({3, 9, 20, nullptr_value, nullptr_value, 15, 7}, nullptr_value);
    vector<vector<int>> expected = {
        {3},
        {9, 20},
        {15, 7}
    };
    vector<vector<int>> res = s.levelOrder(root);
    assert(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({1}, nullptr_value);
    expected = {{1}};
    res = s.levelOrder(root);
    assert(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({}, nullptr_value);
    expected = {};
    res = s.levelOrder(root);
    assert(res == expected);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
