//
// Created by 1412 on 2025/11/6.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        dp[0][1] = 1;  // can also set dp[1][0] = 1
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (!obstacleGrid[i - 1][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

void test() {
    Solution s;
    std::vector<std::vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    CHECK(s.uniquePathsWithObstacles(obstacleGrid) == 2);

    obstacleGrid = {
        {0, 1},
        {0, 0}
    };
    CHECK(s.uniquePathsWithObstacles(obstacleGrid) == 1);

    obstacleGrid = {
        {1, 0}
    };
    CHECK(s.uniquePathsWithObstacles(obstacleGrid) == 0);
}

int main() {
    test();
    return 0;
}
