//
// Created by 1412 on 2026/11/1.
//

#include <bits/stdc++.h>

#include "common.h"

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;

        auto contribute = [&](const size_t i, const size_t j) {
            int cnt = 0;
            // up
            if (i == 0 || grid[i - 1][j] == 0) {
                cnt++;
            }
            // down
            if (i == grid.size() - 1 || grid[i + 1][j] == 0) {
                cnt++;
            }
            // left
            if (j == 0 || grid[i][j - 1] == 0) {
                cnt++;
            }
            // right
            if (j == grid[0].size() - 1 || grid[i][j + 1] == 0) {
                cnt++;
            }
            return cnt;
        };

        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    res += contribute(i, j);
                }
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    CHECK(s.islandPerimeter(grid) == 16);

    grid = {{1}};
    CHECK(s.islandPerimeter(grid) == 4);

    grid = {
        {1, 0}
    };
    CHECK(s.islandPerimeter(grid) == 4);
}

int main() {
    test();
    return 0;
}
