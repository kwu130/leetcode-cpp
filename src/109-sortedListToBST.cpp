//
// Created by 1412 on 2025/12/5.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using listHelper::ListNode;
using treeHelper::TreeNode;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) { return build(head, nullptr); }

private:
    TreeNode* build(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode* slow = left;
        ListNode* fast = left;
        // find the middle node
        while (fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(left, slow);
        root->right = build(slow->next, right);
        return root;
    }
};

void test() {
    Solution s;
    ListNode* head = listHelper::build({-10, -3, 0, 5, 9});
    TreeNode* root = s.sortedListToBST(head);
    int nullptr_value = -1;
    TreeNode* expected = treeHelper::build({0, -3, 9, -10, nullptr_value, 5}, nullptr_value);
    assert(treeHelper::equal(root, expected));
    listHelper::free(head);
    treeHelper::free(root);
    treeHelper::free(expected);

    head = listHelper::build({});
    root = s.sortedListToBST(head);
    expected = treeHelper::build({}, nullptr_value);
    assert(treeHelper::equal(root, expected));
    listHelper::free(head);
    treeHelper::free(root);
    treeHelper::free(expected);
}

int main() {
    test();
    return 0;
}
