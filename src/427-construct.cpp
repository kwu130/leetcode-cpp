//
// Created by 1412 on 2026/10/30.
//

#include <bits/stdc++.h>

#include "common.h"

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        auto all_same = [&](int i, int j, int k) {
            for (int row = 0; row < k; ++row) {
                for (int col = 0; col < k; ++col) {
                    if (grid[i][j] != grid[i + row][j + col]) {
                        return false;
                    }
                }
            }
            return true;
        };

        function<Node*(int, int, int)> dfs = [&](int i, int j, int k) {
            if (all_same(i, j, k)) {
                return new Node(grid[i][j] == 1, true);
            }
            const int half = k / 2;
            return new Node(true, false, dfs(i, j, half), dfs(i, j + half, half), dfs(i + half, j, half),
                            dfs(i + half, j + half, half));
        };

        return dfs(0, 0, grid.size());
    }
};

void test() {
    Solution s;
    // Internal nodes may have either value; only leaf values are meaningful.
    function<bool(Node*, const vector<vector<int>>&, int, int, int)> validate =
        [&](Node* node, const vector<vector<int>>& grid, int row, int col, int size) {
            if (node == nullptr) {
                return false;
            }
            bool uniform = true;
            for (int i = row; i < row + size; ++i) {
                for (int j = col; j < col + size; ++j) {
                    if (grid[i][j] != grid[row][col]) {
                        uniform = false;
                    }
                }
            }
            if (uniform) {
                return node->isLeaf && node->val == (grid[row][col] == 1) && node->topLeft == nullptr &&
                       node->topRight == nullptr && node->bottomLeft == nullptr && node->bottomRight == nullptr;
            }
            const int half = size / 2;
            return !node->isLeaf && validate(node->topLeft, grid, row, col, half) &&
                   validate(node->topRight, grid, row, col + half, half) &&
                   validate(node->bottomLeft, grid, row + half, col, half) &&
                   validate(node->bottomRight, grid, row + half, col + half, half);
        };
    function<void(Node*)> freeTree = [&](Node* node) {
        if (node == nullptr) {
            return;
        }
        freeTree(node->topLeft);
        freeTree(node->topRight);
        freeTree(node->bottomLeft);
        freeTree(node->bottomRight);
        delete node;
    };

    vector<vector<vector<int>>> cases = {
        {{0}},
        {{1}},
        vector<vector<int>>(4, vector<int>(4, 0)),
        vector<vector<int>>(4, vector<int>(4, 1)),
        {{0, 1}, {1, 0}},
        {{1, 0}, {0, 0}},
        {{0, 1}, {0, 0}},
        {{0, 0}, {1, 0}},
        {{0, 0}, {0, 1}},
        {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}},
        {
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         },
    };
    for (auto& grid : cases) {
        Node* root = s.construct(grid);
        CHECK(validate(root, grid, 0, 0, grid.size()));
        freeTree(root);
    }
}

int main() {
    test();
    return 0;
}
