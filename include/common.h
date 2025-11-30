#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <ranges>

namespace listHelper {
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0),
          next(nullptr) {}
    explicit ListNode(int x)
        : val(x),
          next(nullptr) {}
    ListNode(const int x, ListNode* next)
        : val(x),
          next(next) {}
};

inline ListNode* build(const std::vector<int>& vec) {
    if (vec.empty()) return nullptr;
    auto* head = new ListNode(vec[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vec.size(); i++) {
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }

    return head;
}

inline bool equal(const ListNode* lhs, const ListNode* rhs) {
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->val != rhs->val) {
            return false;
        }
        lhs = lhs->next;
        rhs = rhs->next;
    }

    return lhs == nullptr && rhs == nullptr;
}

inline void print(const ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

inline void free(ListNode* head) {
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}
}  // namespace listHelper

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
    TreeNode(const int x, TreeNode* left, TreeNode* right)
        : val(x),
          left(left),
          right(right) {}
};

inline TreeNode* build(const std::vector<int>& vec, int nullptr_val = -1) {
    if (vec.empty() || vec[0] == nullptr_val) return nullptr;

    std::queue<TreeNode*> q;
    auto* root = new TreeNode(vec[0]);
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < vec.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (i < vec.size() && vec[i] != nullptr_val) {
            cur->left = new TreeNode(vec[i]);
            q.push(cur->left);
        }
        i++;

        if (i < vec.size() && vec[i] != nullptr_val) {
            cur->right = new TreeNode(vec[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// level order
inline void print(const TreeNode* root) {
    if (root == nullptr) {
        std::cout << "null" << std::endl;
        return;
    }

    std::queue<const TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        const TreeNode* cur = q.front();
        q.pop();

        if (cur == nullptr) {
            std::cout << "null ";
        } else {
            std::cout << cur->val << " ";
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    std::cout << std::endl;
}

inline bool equal(const TreeNode* a, const TreeNode* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    if (a->val != b->val) return false;

    return equal(a->left, b->left) && equal(a->right, b->right);
}

inline void free(const TreeNode* root) {
    if (root == nullptr) return;
    free(root->left);
    free(root->right);
    delete root;
}
}  // namespace treeHelper

namespace compareHelper {
template <typename V>
bool equalIgnoreOrder(const V& a, const V& b) {
    if (a.size() != b.size()) return false;

    V aa = a;
    V bb = b;

    using Elem = typename V::value_type;

    if constexpr (requires(Elem e) {
                      e.begin();
                      e.end();
                  }) {
        for (auto& v : aa) std::ranges::sort(v);
        for (auto& v : bb) std::ranges::sort(v);
    }

    std::ranges::sort(aa);
    std::ranges::sort(bb);

    return aa == bb;
}
}  // namespace compareHelper
#endif  // LEETCODE_COMMON_H
