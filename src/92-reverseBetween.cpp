//
// Created by 1412 on 2025/11/22.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;
        ListNode dummy = ListNode(-1, head);
        ListNode* pre = &dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode* tail = pre->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* tmp = tail->next;
            tail->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy.next;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({1, 2, 3, 4, 5});
    ListNode* expected = listHelper::build({1, 4, 3, 2, 5});
    ListNode* res = s.reverseBetween(head, 2, 4);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    head = listHelper::build({5});
    expected = listHelper::build({5});
    res = s.reverseBetween(head, 1, 1);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
