//
// Created by 1412 on 2025/11/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
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
    assert(s.uniquePaths(3, 7) == 28);
    assert(s.uniquePaths(3, 2) == 3);
}

int main() {
    test();
    return 0;
}
