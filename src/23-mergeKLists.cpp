//
// Created by 1412 on 2025/10/16.
//

#include <queue>
#include <vector>

#include "list_helper.h"
#include "test_helper.h"


using listHelper::ListNode;

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* lhs, ListNode* rhs) { return lhs->val > rhs->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode dummy = ListNode(-1);
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};

void test() {
    Solution s;
    ListNode* l1 = listHelper::build({1, 4, 5});
    ListNode* l2 = listHelper::build({1, 3, 4});
    ListNode* l3 = listHelper::build({2, 6});
    std::vector<ListNode*> lists = {l1, l2, l3};
    ListNode* expected = listHelper::build({1, 1, 2, 3, 4, 4, 5, 6});
    ListNode* res = s.mergeKLists(lists);
    CHECK(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    lists = {};
    expected = listHelper::build({});
    res = s.mergeKLists(lists);
    CHECK(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);

    lists = {nullptr};
    expected = listHelper::build({});
    res = s.mergeKLists(lists);
    CHECK(listHelper::equal(res, expected));
    listHelper::free(res);
    listHelper::free(expected);
}

int main() {
    test();
    return 0;
}
