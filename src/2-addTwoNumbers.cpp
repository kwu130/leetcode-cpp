//
// Created by 1412 on 2025/9/24.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;
using namespace listHelper;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a, b, c, carry = 0;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while (l1 || l2 || carry) {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            c = a + b + carry;
            carry = c / 10;
            cur->next = new ListNode(c % 10);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return head->next;
    }
};

void test() {
    Solution s;
    ListNode* l1 = new ListNode(vector<int>{2, 4, 3});
    ListNode* l2 = new ListNode(vector<int>{5, 6, 4});
    ListNode* expected = new ListNode(vector<int>{7, 0, 8});
    ListNode* res = s.addTwoNumbers(l1, l2);
    assert(res->equal(expected));
    freeList(l1);
    freeList(l2);
    freeList(expected);

    l1 = new ListNode(vector<int>{0});
    l2 = new ListNode(vector<int>{0});
    expected = new ListNode(vector<int>{0});
    res = s.addTwoNumbers(l1, l2);
    assert(res->equal(expected));
    freeList(l1);
    freeList(l2);
    freeList(expected);

    l1 = new ListNode(vector<int>{9, 9, 9, 9, 9, 9, 9});
    l2 = new ListNode(vector<int>{9, 9, 9, 9});
    expected = new ListNode(vector<int>{8, 9, 9, 9, 0, 0, 0, 1});
    res = s.addTwoNumbers(l1, l2);
    assert(res->equal(expected));
    freeList(l1);
    freeList(l2);
    freeList(expected);
}

int main() {
    test();
    return 0;
}
