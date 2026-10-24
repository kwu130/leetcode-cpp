//
// Created by 1412 on 2025/12/13.
//

#include <stack>
#include <optional>

#include "common.h"


using treeHelper::TreeNode;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        std::stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left);
            if (!s.empty()) {
                node->right = s.top();
            }
            node->left = nullptr;
        }
    }
};

void test() {
    Solution s;
    constexpr auto nullptr_val = std::nullopt;
    TreeNode* root = treeHelper::build({1, 2, 5, 3, 4, nullptr_val, 6});
    TreeNode* expected =
        treeHelper::build({1, nullptr_val, 2, nullptr_val, 3, nullptr_val, 4, nullptr_val, 5, nullptr_val, 6});
    s.flatten(root);
    CHECK(treeHelper::equal(root, expected));
    treeHelper::free(root);
    treeHelper::free(expected);

    root = treeHelper::build({});
    expected = treeHelper::build({});
    s.flatten(root);
    CHECK(treeHelper::equal(root, expected));
    treeHelper::free(root);
    treeHelper::free(expected);

    root = treeHelper::build({0});
    expected = treeHelper::build({0});
    s.flatten(root);
    CHECK(treeHelper::equal(root, expected));
    treeHelper::free(root);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
