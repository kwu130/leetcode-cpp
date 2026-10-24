//
// Created by 1412 on 2025/12/7.
//

#include <algorithm>
#include <cstdlib>
#include <optional>

#include "common.h"


using treeHelper::TreeNode;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return std::abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) &&
               isBalanced(root->right);
    }

private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(height(root->left), height(root->right)) + 1;
    }
};

void test() {
    Solution s;
    constexpr auto nullptr_value = std::nullopt;
    TreeNode* root = treeHelper::build({3, 9, 20, nullptr_value, nullptr_value, 15, 7});
    CHECK(s.isBalanced(root) == true);
    treeHelper::free(root);

    root = treeHelper::build({1, 2, 2, 3, 3, nullptr_value, nullptr_value, 4, 4});
    CHECK(s.isBalanced(root) == false);
    treeHelper::free(root);

    root = treeHelper::build({});
    CHECK(s.isBalanced(root) == true);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
