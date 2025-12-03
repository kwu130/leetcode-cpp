//
// Created by 1412 on 2025/12/3.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, postorder, 0, inorder.size());
    }

private:
    TreeNode* build(vector<int>& inorder, int in_start, vector<int>& postorder, int post_start, int len) {
        if (len == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[post_start + len - 1]);
        const int index =
            find(inorder.begin() + in_start, inorder.begin() + in_start + len, root->val) - inorder.begin();
        root->left = build(inorder, in_start, postorder, post_start, index - in_start);
        root->right = build(inorder, index + 1, postorder, post_start + index - in_start, len - index + in_start - 1);
        return root;
    }
};

void test() {
    Solution s;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    int nullptr_val = -1;
    TreeNode* expected = treeHelper::build({3, 9, 20, nullptr_val, nullptr_val, 15, 7}, nullptr_val);
    TreeNode* res = s.buildTree(inorder, postorder);
    assert(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);

    inorder = {1};
    postorder = {1};
    expected = treeHelper::build(vector<int>{1}, nullptr_val);
    res = s.buildTree(inorder, postorder);
    assert(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
