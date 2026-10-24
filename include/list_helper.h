#ifndef LEETCODE_LIST_HELPER_H
#define LEETCODE_LIST_HELPER_H

#include <iostream>
#include <vector>

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
    ListNode(int x, ListNode* next)
        : val(x),
          next(next) {}
};

inline ListNode* build(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;

    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummy.next;
}

inline bool equal(const ListNode* lhs, const ListNode* rhs) {
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->val != rhs->val) return false;
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
    std::cout << "nullptr\n";
}

inline void free(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

}  // namespace listHelper

#endif  // LEETCODE_LIST_HELPER_H
