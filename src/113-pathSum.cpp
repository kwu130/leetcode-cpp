//
// Created by 1412 on 2025/12/9.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        dfs(root, targetSum, res, {});
        return res;
    }

private:
    void dfs(TreeNode* node, int targetSum, vector<vector<int>>& res, vector<int>&& path) {
        if (node == nullptr) return;
        path.emplace_back(node->val);
        targetSum -= node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (targetSum == 0) {
                res.emplace_back(path);
            }
            return;
        }
        if (node->left != nullptr) {
            dfs(node->left, targetSum, res, std::move(path));
            path.pop_back();
        }
        if (node->right != nullptr) {
            dfs(node->right, targetSum, res, std::move(path));
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    int nullptr_value = -1;
    TreeNode* root =
        treeHelper::build({5, 4, 8, 11, nullptr_value, 13, 4, 7, 2, nullptr_value, nullptr_value, 5, 1}, nullptr_value);
    vector<vector<int>> expected = {
        {5, 4, 11, 2},
        {5, 8,  4, 5}
    };
    vector<vector<int>> res = s.pathSum(root, 22);
    assert(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({1, 2, 3}, nullptr_value);
    expected = {};
    res = s.pathSum(root, 5);
    assert(res == expected);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
