//
// Created by 1412 on 2025/11/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;  // ""
        if (s[0] == '0') {
            dp[1] = 0;
        } else {
            dp[1] = 1;
        }
        for (int i = 2; i <= static_cast<int>(s.size()); i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};

void test() {
    Solution s;
    assert(s.numDecodings("12") == 2);
    assert(s.numDecodings("226") == 3);
    assert(s.numDecodings("06") == 0);
}

int main() {
    test();
    return 0;
}
