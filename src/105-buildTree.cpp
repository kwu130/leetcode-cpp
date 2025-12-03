//
// Created by 1412 on 2025/12/3.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, inorder, 0, preorder.size());
    }

private:
    TreeNode* build(vector<int>& preorder, int pre_start, vector<int>& inorder, int in_start, int len) {
        if (len == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        const int index =
            find(inorder.begin() + in_start, inorder.begin() + in_start + len, root->val) - inorder.begin();
        root->left = build(preorder, pre_start + 1, inorder, in_start, index - in_start);
        root->right = build(preorder, pre_start + index - in_start + 1, inorder, index + 1, len - index + in_start - 1);
        return root;
    }
};

void test() {
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    int nullptr_val = -1;
    TreeNode* expected = treeHelper::build({3, 9, 20, nullptr_val, nullptr_val, 15, 7}, nullptr_val);
    TreeNode* res = s.buildTree(preorder, inorder);
    assert(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);

    preorder = {1};
    inorder = {1};
    expected = treeHelper::build(vector<int>{1}, nullptr_val);
    res = s.buildTree(preorder, inorder);
    assert(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
