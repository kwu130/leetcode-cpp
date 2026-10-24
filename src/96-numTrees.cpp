//
// Created by 1412 on 2025/11/25.
//

#include <vector>

#include "common.h"


class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

void test() {
    Solution s;
    CHECK(s.numTrees(3) == 5);
    CHECK(s.numTrees(1) == 1);
}

int main() {
    test();
    return 0;
}
