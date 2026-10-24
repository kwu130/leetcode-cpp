//
// Created by 1412 on 2025/11/30.
//


#include <optional>

#include "common.h"


using TreeNode = treeHelper::TreeNode;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { return sameTree(p, q); }

private:
    bool sameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        return p->val == q->val && sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }
};

void test() {
    Solution s;
    constexpr auto nullptr_value = std::nullopt;
    TreeNode* root1 = treeHelper::build({1, 2, 3});
    TreeNode* root2 = treeHelper::build({1, 2, 3});
    CHECK(s.isSameTree(root1, root2) == true);
    treeHelper::free(root1);
    treeHelper::free(root2);

    root1 = treeHelper::build({1, 2});
    root2 = treeHelper::build({1, nullptr_value, 2});
    CHECK(s.isSameTree(root1, root2) == false);
    treeHelper::free(root1);
    treeHelper::free(root2);

    root1 = treeHelper::build({1, 2, 1});
    root2 = treeHelper::build({1, 1, 2});
    CHECK(s.isSameTree(root1, root2) == false);
    treeHelper::free(root1);
    treeHelper::free(root2);

    root1 = treeHelper::build({-1, nullptr_value, -2});
    root2 = treeHelper::build({-1, nullptr_value, -2});
    CHECK(s.isSameTree(root1, root2) == true);
    treeHelper::free(root1);
    treeHelper::free(root2);
}

int main() {
    test();
    return 0;
}
