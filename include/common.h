#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <cassert>

namespace listHelper {
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0),
          next(nullptr) {}
    ListNode(int x)
        : val(x),
          next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x),
          next(next) {}
    ListNode(const std::vector<int>& vec)
        : next(nullptr) {
        assert(!vec.empty());
        val = vec[0];
        ListNode* cur = this;
        for (int i = 1; i < vec.size(); i++) {
            cur->next = new ListNode(vec[i]);
            cur = cur->next;
        }
    }

    bool equal(const ListNode* other) const {
        const ListNode* current_this = this;
        const ListNode* current_other = other;

        while (current_this != nullptr && current_other != nullptr) {
            if (current_this->val != current_other->val) {
                return false;
            }
            current_this = current_this->next;
            current_other = current_other->next;
        }

        return current_this == nullptr && current_other == nullptr;
    }
};

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}
}  // namespace listHelper

namespace compareHelper {
template <typename T>
bool equalIgnoreOrder(std::vector<std::vector<T>> a, std::vector<std::vector<T>> b) {
    if (a.size() != b.size()) return false;

    for (auto& v : a) std::sort(v.begin(), v.end());
    for (auto& v : b) std::sort(v.begin(), v.end());

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
}
}  // namespace compareHelper
#endif  // LEETCODE_COMMON_H
