//
// Created by 1412 on 2025/10/15.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre, *first, *second;
        pre = nullptr;
        first = second = head;
        while (n--) {
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            pre = second;
            second = second->next;
        }
        if (pre == nullptr) {
            head = head->next;
        } else {
            pre->next = second->next;
        }
        delete second;

        return head;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({1, 2, 3, 4, 5});
    ListNode* expected = listHelper::build({1, 2, 3, 5});
    ListNode* res = s.removeNthFromEnd(head, 2);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    head = listHelper::build({1});
    expected = nullptr;
    res = s.removeNthFromEnd(head, 1);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    head = listHelper::build({1, 2});
    expected = listHelper::build({1});
    res = s.removeNthFromEnd(head, 1);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
