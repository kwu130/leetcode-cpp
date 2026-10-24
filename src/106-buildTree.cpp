//
// Created by 1412 on 2025/12/3.
//

#include <algorithm>
#include <vector>
#include <optional>

#include "common.h"


using treeHelper::TreeNode;

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        return build(inorder, 0, postorder, 0, inorder.size());
    }

private:
    TreeNode* build(std::vector<int>& inorder, int in_start, std::vector<int>& postorder, int post_start, int len) {
        if (len == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[post_start + len - 1]);
        const int index =
            std::find(inorder.begin() + in_start, inorder.begin() + in_start + len, root->val) - inorder.begin();
        root->left = build(inorder, in_start, postorder, post_start, index - in_start);
        root->right = build(inorder, index + 1, postorder, post_start + index - in_start, len - index + in_start - 1);
        return root;
    }
};

void test() {
    Solution s;
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};
    constexpr auto nullptr_val = std::nullopt;
    TreeNode* expected = treeHelper::build({3, 9, 20, nullptr_val, nullptr_val, 15, 7});
    TreeNode* res = s.buildTree(inorder, postorder);
    CHECK(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);

    inorder = {1};
    postorder = {1};
    expected = treeHelper::build({1});
    res = s.buildTree(inorder, postorder);
    CHECK(treeHelper::equal(res, expected));
    treeHelper::free(res);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
