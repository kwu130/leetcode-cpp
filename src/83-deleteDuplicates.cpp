//
// Created by 1412 on 2025/11/17.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        while (head) {
            while (head->next && head->val == head->next->val) {
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            pre->next = head;
            pre = head;
            head = head->next;
        }
        return dummy.next;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({1, 1, 2});
    ListNode* expect = listHelper::build({1, 2});
    ListNode* res = s.deleteDuplicates(head);
    assert(listHelper::equal(res, expect));
    listHelper::free(res);
    listHelper::free(expect);

    head = listHelper::build({1, 1, 2, 3, 3});
    expect = listHelper::build({1, 2, 3});
    res = s.deleteDuplicates(head);
    assert(listHelper::equal(res, expect));
    listHelper::free(res);
    listHelper::free(expect);
}

int main() {
    test();
    return 0;
}
