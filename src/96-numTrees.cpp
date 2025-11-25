//
// Created by 1412 on 2025/11/25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
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
    assert(s.numTrees(3) == 5);
    assert(s.numTrees(1) == 1);
}

int main() {
    test();
    return 0;
}
