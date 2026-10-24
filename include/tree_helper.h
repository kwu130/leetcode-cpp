#ifndef LEETCODE_TREE_HELPER_H
#define LEETCODE_TREE_HELPER_H

#include <initializer_list>
#include <iostream>
#include <optional>
#include <queue>
#include <vector>

namespace treeHelper {

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
        : val(0),
          left(nullptr),
          right(nullptr) {}
    explicit TreeNode(int x)
        : val(x),
          left(nullptr),
          right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x),
          left(left),
          right(right) {}
};

inline TreeNode* build(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values.front().has_value()) return nullptr;

    auto* root = new TreeNode(*values.front());
    std::queue<TreeNode*> nodes;
    nodes.push(root);

    std::size_t index = 1;
    while (!nodes.empty() && index < values.size()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (values[index].has_value()) {
            current->left = new TreeNode(*values[index]);
            nodes.push(current->left);
        }
        ++index;

        if (index < values.size() && values[index].has_value()) {
            current->right = new TreeNode(*values[index]);
            nodes.push(current->right);
        }
        ++index;
    }

    return root;
}

inline TreeNode* build(std::initializer_list<std::optional<int>> values) {
    return build(std::vector<std::optional<int>>(values));
}

// Compatibility overload for existing callers that use a sentinel value.
inline TreeNode* build(const std::vector<int>& values, int null_value = -1) {
    std::vector<std::optional<int>> optional_values;
    optional_values.reserve(values.size());
    for (int value : values) {
        if (value == null_value) {
            optional_values.emplace_back(std::nullopt);
        } else {
            optional_values.emplace_back(value);
        }
    }
    return build(optional_values);
}

inline void print(const TreeNode* root) {
    if (root == nullptr) {
        std::cout << "null\n";
        return;
    }

    std::queue<const TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        const TreeNode* current = nodes.front();
        nodes.pop();

        if (current == nullptr) {
            std::cout << "null ";
            continue;
        }

        std::cout << current->val << ' ';
        nodes.push(current->left);
        nodes.push(current->right);
    }
    std::cout << '\n';
}

inline bool equal(const TreeNode* lhs, const TreeNode* rhs) {
    if (lhs == nullptr || rhs == nullptr) return lhs == rhs;
    return lhs->val == rhs->val && equal(lhs->left, rhs->left) && equal(lhs->right, rhs->right);
}

inline void free(TreeNode* root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}

}  // namespace treeHelper

#endif  // LEETCODE_TREE_HELPER_H
