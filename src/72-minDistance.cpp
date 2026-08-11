//
// Created by 1412 on 2025/11/10.
//

#include <algorithm>
#include <string>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        const int m = word1.size(), n = word2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 分别对应 替换 插入 删除
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

void test() {
    Solution s;
    CHECK(s.minDistance("horse", "ros") == 3);
    CHECK(s.minDistance("intention", "execution") == 5);
}

int main() {
    test();
    return 0;
}
