//
// Created by 1412 on 2025/11/18.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy1 = ListNode(-1);
        ListNode dummy2 = ListNode(-1);
        ListNode *p1 = &dummy1, *p2 = &dummy2;
        while (head != nullptr) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = nullptr;
        p1->next = dummy2.next;

        return dummy1.next;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({1, 4, 3, 2, 5, 2});
    ListNode* expected = listHelper::build({1, 2, 2, 4, 3, 5});
    ListNode* res = s.partition(head, 3);
    assert(listHelper::equal(res, expected));
    listHelper::free(head);
    listHelper::free(expected);

    head = listHelper::build({2, 1});
    expected = listHelper::build({1, 2});
    res = s.partition(head, 2);
    assert(listHelper::equal(res, expected));
    listHelper::free(head);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
