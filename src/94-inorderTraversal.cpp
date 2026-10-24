//
// Created by 1412 on 2025/11/23.
//

#include <stack>
#include <vector>
#include <optional>

#include "common.h"


using treeHelper::TreeNode;

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> s;
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
    constexpr auto nullptr_val = std::nullopt;
    TreeNode* root = treeHelper::build({1, nullptr_val, 2, 3});
    std::vector<int> expected = {1, 3, 2};
    std::vector<int> res = s.inorderTraversal(root);
    CHECK(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({});
    expected = {};
    res = s.inorderTraversal(root);
    CHECK(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({1});
    expected = {1};
    res = s.inorderTraversal(root);
    CHECK(res == expected);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
