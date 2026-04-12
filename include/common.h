#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

// Helper utilities for LeetCode problem solving
// Provides common data structures and operations for linked lists, trees, and comparisons

namespace listHelper {

// Linked list node definition
struct ListNode {
    int val;
    ListNode* next;

    ListNode()
        : val(0),
          next(nullptr) {}
    explicit ListNode(int x)
        : val(x),
          next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x),
          next(next) {}
};

// Build a linked list from a vector
inline ListNode* build(const std::vector<int>& vec) {
    if (vec.empty()) return nullptr;

    auto* head = new ListNode(vec[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vec.size(); ++i) {
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    return head;
}

// Compare two linked lists for equality
inline bool equal(const ListNode* lhs, const ListNode* rhs) {
    while (lhs && rhs) {
        if (lhs->val != rhs->val) return false;
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return lhs == nullptr && rhs == nullptr;
}

// Print linked list in format: val -> val -> nullptr
inline void print(const ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Free all nodes in the linked list
inline void free(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

}  // namespace listHelper

namespace treeHelper {

// Binary tree node definition
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

// Build a binary tree from level-order traversal vector
// nullptr_val represents null nodes (default: -1)
inline TreeNode* build(const std::vector<int>& vec, int nullptr_val = -1) {
    if (vec.empty() || vec[0] == nullptr_val) return nullptr;

    std::queue<TreeNode*> q;
    auto* root = new TreeNode(vec[0]);
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < vec.size()) {
        TreeNode* cur = q.front();
        q.pop();

        // Process left child
        if (i < vec.size() && vec[i] != nullptr_val) {
            cur->left = new TreeNode(vec[i]);
            q.push(cur->left);
        }
        ++i;

        // Process right child
        if (i < vec.size() && vec[i] != nullptr_val) {
            cur->right = new TreeNode(vec[i]);
            q.push(cur->right);
        }
        ++i;
    }
    return root;
}

// Print tree in level-order traversal
inline void print(const TreeNode* root) {
    if (!root) {
        std::cout << "null" << std::endl;
        return;
    }

    std::queue<const TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        const TreeNode* cur = q.front();
        q.pop();

        if (!cur) {
            std::cout << "null ";
        } else {
            std::cout << cur->val << " ";
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    std::cout << std::endl;
}

// Recursively compare two trees for equality
inline bool equal(const TreeNode* a, const TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;
    return equal(a->left, b->left) && equal(a->right, b->right);
}

// Recursively free all nodes in the tree
inline void free(TreeNode* root) {
    if (!root) return;
    free(root->left);
    free(root->right);
    delete root;
}

}  // namespace treeHelper

namespace compareHelper {

// Compare two containers ignoring element order
// Supports nested containers (e.g., vector<vector<int>>)
template <typename V>
bool equalIgnoreOrder(const V& a, const V& b) {
    if (a.size() != b.size()) return false;

    // Create copies to avoid modifying originals
    V aa = a;
    V bb = b;

    using Elem = typename V::value_type;

    // If elements are themselves sortable containers, sort them first
    if constexpr (requires(Elem e) {
                      { e.begin() } -> std::input_or_output_iterator;
                      { e.end() } -> std::input_or_output_iterator;
                  }) {
        for (auto& v : aa) std::ranges::sort(v);
        for (auto& v : bb) std::ranges::sort(v);
    }

    // Sort outer containers
    std::ranges::sort(aa);
    std::ranges::sort(bb);

    return aa == bb;
}

}  // namespace compareHelper

#endif  // LEETCODE_COMMON_H
