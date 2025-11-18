//
// Created by 1412 on 2025/10/16.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode *pre = &dummy, *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* next = cur->next;
            pre->next = next;
            cur->next = next->next;
            next->next = cur;
            pre = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};

void test() {
    Solution s;
    ListNode* l1 = listHelper::build({1, 2, 3, 4});
    ListNode* expected = listHelper::build({2, 1, 4, 3});
    ListNode* res = s.swapPairs(l1);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    l1 = listHelper::build({});
    expected = listHelper::build({});
    res = s.swapPairs(l1);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    l1 = listHelper::build({1});
    expected = listHelper::build({1});
    res = s.swapPairs(l1);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
