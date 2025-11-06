//
// Created by 1412 on 2025/11/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
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
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    assert(s.uniquePathsWithObstacles(obstacleGrid) == 2);

    obstacleGrid = {
        {0, 1},
        {0, 0}
    };
    assert(s.uniquePathsWithObstacles(obstacleGrid) == 1);

    obstacleGrid = {
        {1, 0}
    };
    assert(s.uniquePathsWithObstacles(obstacleGrid) == 0);
}

int main() {
    test();
    return 0;
}
