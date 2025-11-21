//
// Created by 1412 on 2025/11/5.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = 0;
        ListNode *cur = head, *pre = nullptr, *tail = nullptr;
        while (cur) {
            len++;
            tail = cur;
            cur = cur->next;
        }
        k %= len;
        if (k == 0) return head;
        int i = len - k;
        cur = head;
        while (i--) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
        tail->next = head;
        return cur;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({1, 2, 3, 4, 5});
    ListNode* expected = listHelper::build({4, 5, 1, 2, 3});
    ListNode* res = s.rotateRight(head, 2);
    assert(listHelper::equal(res, expected));
    listHelper::free(head);
    listHelper::free(expected);

    head = listHelper::build({0, 1, 2});
    expected = listHelper::build({2, 0, 1});
    res = s.rotateRight(head, 4);
    assert(listHelper::equal(res, expected));
    listHelper::free(head);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
