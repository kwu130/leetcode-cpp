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


namespace compareHelper {
template <typename T>
bool equalIgnoreOrder(std::vector<T> a, std::vector<T> b) {
    if (a.size() != b.size()) return false;

    std::ranges::sort(a);
    std::ranges::sort(b);

    return a == b;
}

template <typename T>
bool equalIgnoreOrder(std::vector<std::vector<T>> a, std::vector<std::vector<T>> b) {
    if (a.size() != b.size()) return false;

    for (auto& v : a) std::ranges::sort(v);
    for (auto& v : b) std::ranges::sort(v);

    std::ranges::sort(a);
    std::ranges::sort(b);

    return a == b;
}
}  // namespace compareHelper
#endif  // LEETCODE_COMMON_H
