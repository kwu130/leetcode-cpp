//
// Created by 1412 on 2025/10/16.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;
using listHelper::ListNode;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* lhs, ListNode* rhs) { return lhs->val > rhs->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};

void test() {
    Solution s;
    ListNode* l1 = listHelper::build({1, 4, 5});
    ListNode* l2 = listHelper::build({1, 3, 4});
    ListNode* l3 = listHelper::build({2, 6});
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* expected = listHelper::build({1, 1, 2, 3, 4, 4, 5, 6});
    ListNode* res = s.mergeKLists(lists);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    lists = {};
    expected = listHelper::build({});
    res = s.mergeKLists(lists);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    lists = {nullptr};
    expected = listHelper::build({});
    res = s.mergeKLists(lists);
    assert(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
