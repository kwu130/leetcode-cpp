//
// Created by 1412 on 2025/11/24.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;
using treeHelper::TreeNode;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {nullptr};
        }
        return generateTrees(1, n);
    }

private:
    vector<TreeNode*> generateTrees(int min, int max) {
        if (min > max) {
            return {nullptr};
        }
        vector<TreeNode*> res;
        for (int i = min; i <= max; i++) {
            auto left = generateTrees(min, i - 1);
            auto right = generateTrees(i + 1, max);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<TreeNode*> res = s.generateTrees(3);
    vector<TreeNode*> expected;
    int nullptr_val = -1;
    expected.push_back(treeHelper::build({1, nullptr_val, 2, nullptr_val, 3}, nullptr_val));
    expected.push_back(treeHelper::build({1, nullptr_val, 3, 2}, nullptr_val));
    expected.push_back(treeHelper::build({2, 1, 3}, nullptr_val));
    expected.push_back(treeHelper::build({3, 1, nullptr_val, nullptr_val, 2}, nullptr_val));
    expected.push_back(treeHelper::build({3, 2, nullptr_val, 1}, nullptr_val));
    for (size_t i = 0; i < res.size(); i++) {
        assert(treeHelper::equal(res[i], expected[i]));
        treeHelper::free(res[i]);
        treeHelper::free(expected[i]);
    }

    res = s.generateTrees(1);
    expected.clear();
    expected.push_back(treeHelper::build({1}, nullptr_val));
    for (size_t i = 0; i < res.size(); i++) {
        assert(treeHelper::equal(res[i], expected[i]));
        treeHelper::free(res[i]);
        treeHelper::free(expected[i]);
    }
}

int main() {
    test();
    return 0;
}
