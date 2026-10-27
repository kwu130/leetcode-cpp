//
// Created by 1412 on 2025/11/9.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

void test() {
    Solution s;
    CHECK(s.climbStairs(2) == 2);
    CHECK(s.climbStairs(3) == 3);
}

int main() {
    test();
    return 0;
}
