//
// Created by 1412 on 2025/10/16.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = ListNode(-1);
        ListNode* cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

void test() {
    Solution s;
    ListNode* l1 = listHelper::build({1, 2, 4});
    ListNode* l2 = listHelper::build({1, 3, 4});
    ListNode* expected = listHelper::build({1, 1, 2, 3, 4, 4});
    ListNode* res = s.mergeTwoLists(l1, l2);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    l1 = listHelper::build({});
    l2 = listHelper::build({});
    expected = listHelper::build({});
    res = s.mergeTwoLists(l1, l2);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    l1 = listHelper::build({});
    l2 = listHelper::build({0});
    expected = listHelper::build({0});
    res = s.mergeTwoLists(l1, l2);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
