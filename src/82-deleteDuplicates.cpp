//
// Created by 1412 on 2025/11/17.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        while (head) {
            bool duplicate = false;
            while (head->next && head->val == head->next->val) {
                duplicate = true;
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            if (!duplicate) {
                pre = head;
                head = head->next;
            } else {
                ListNode* tmp = head;
                pre->next = head->next;
                head = head->next;
                delete tmp;
            }
        }
        return dummy.next;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({1, 2, 3, 3, 4, 4, 5});
    ListNode* expect = listHelper::build({1, 2, 5});
    ListNode* res = s.deleteDuplicates(head);
    assert(listHelper::equal(res, expect));
    listHelper::free(res);
    listHelper::free(expect);

    head = listHelper::build({1, 1, 1, 2, 3});
    expect = listHelper::build({2, 3});
    res = s.deleteDuplicates(head);
    assert(listHelper::equal(res, expect));
    listHelper::free(res);
    listHelper::free(expect);
}

int main() {
    test();
    return 0;
}
