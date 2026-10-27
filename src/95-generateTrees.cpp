//
// Created by 1412 on 2025/11/24.
//

#include <bits/stdc++.h>

#include "common.h"


using treeHelper::TreeNode;

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {nullptr};
        }
        return generateTrees(1, n);
    }

private:
    std::vector<TreeNode*> generateTrees(int min, int max) {
        if (min > max) {
            return {nullptr};
        }
        std::vector<TreeNode*> res;
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
    std::vector<TreeNode*> res = s.generateTrees(3);
    std::vector<TreeNode*> expected;
    constexpr auto nullptr_val = std::nullopt;
    expected.push_back(treeHelper::build({1, nullptr_val, 2, nullptr_val, 3}));
    expected.push_back(treeHelper::build({1, nullptr_val, 3, 2}));
    expected.push_back(treeHelper::build({2, 1, 3}));
    expected.push_back(treeHelper::build({3, 1, nullptr_val, nullptr_val, 2}));
    expected.push_back(treeHelper::build({3, 2, nullptr_val, 1}));
    for (std::size_t i = 0; i < res.size(); i++) {
        CHECK(treeHelper::equal(res[i], expected[i]));
        treeHelper::free(res[i]);
        treeHelper::free(expected[i]);
    }

    res = s.generateTrees(1);
    expected.clear();
    expected.push_back(treeHelper::build({1}));
    for (std::size_t i = 0; i < res.size(); i++) {
        CHECK(treeHelper::equal(res[i], expected[i]));
        treeHelper::free(res[i]);
        treeHelper::free(expected[i]);
    }
}

int main() {
    test();
    return 0;
}
