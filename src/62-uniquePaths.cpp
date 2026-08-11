//
// Created by 1412 on 2025/11/6.
//

#include <vector>

#include "test_helper.h"


class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

void test() {
    Solution s;
    CHECK(s.uniquePaths(3, 7) == 28);
    CHECK(s.uniquePaths(3, 2) == 3);
}

int main() {
    test();
    return 0;
}
