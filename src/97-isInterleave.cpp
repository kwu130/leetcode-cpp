//
// Created by 1412 on 2025/11/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const size_t n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) {
            return false;
        }

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;

        for (size_t i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        for (size_t j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (size_t i = 1; i <= n1; ++i) {
            for (size_t j = 1; j <= n2; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n1][n2];
    }
};

void test() {
    Solution s;
    assert(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(s.isInterleave("", "", ""));
}

int main() {
    test();
    return 0;
}
