//
// Created by 1412 on 2025/12/1.
//

#include <algorithm>
#include <cstddef>
#include <queue>
#include <vector>
#include <optional>

#include "common.h"


using treeHelper::TreeNode;

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) return res;
        std::queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while (!q.empty()) {
            std::size_t n = q.size();
            std::vector<int> level;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            if (!left_to_right) {
                std::ranges::reverse(level);
            }
            left_to_right = !left_to_right;
            res.push_back(level);
        }
        return res;
    }
};

void test() {
    Solution s;
    constexpr auto nullptr_value = std::nullopt;
    TreeNode* root = treeHelper::build({3, 9, 20, nullptr_value, nullptr_value, 15, 7});
    std::vector<std::vector<int>> res = s.zigzagLevelOrder(root);
    std::vector<std::vector<int>> expected = {
        {3},
        {20, 9},
        {15, 7}
    };
    CHECK(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({1});
    expected = {{1}};
    res = s.zigzagLevelOrder(root);
    CHECK(res == expected);
    treeHelper::free(root);

    root = treeHelper::build({});
    expected = {};
    res = s.zigzagLevelOrder(root);
    CHECK(res == expected);
    treeHelper::free(root);
}

int main() {
    test();
    return 0;
}
