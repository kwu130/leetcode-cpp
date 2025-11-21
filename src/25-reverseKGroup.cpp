//
// Created by 1412 on 2025/10/16.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            // There are less than k nodes in the list, do nothing.
            if (tail == nullptr) return head;
            tail = tail->next;
        }
        ListNode* newHead = reverseInterval(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }

private:
    // reverse [head, tail)
    ListNode* reverseInterval(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

void test() {
    Solution s;
    ListNode* l1 = listHelper::build({1, 2, 3, 4, 5});
    ListNode* expected = listHelper::build({2, 1, 4, 3, 5});
    ListNode* res = s.reverseKGroup(l1, 2);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    l1 = listHelper::build({1, 2, 3, 4, 5});
    expected = listHelper::build({3, 2, 1, 4, 5});
    res = s.reverseKGroup(l1, 3);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    l1 = listHelper::build({1, 2, 3, 4, 5});
    expected = listHelper::build({5, 4, 3, 2, 1});
    res = s.reverseKGroup(l1, 5);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
