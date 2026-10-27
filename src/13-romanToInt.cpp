//
// Created by 1412 on 2025/10/9.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> m(7);

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int res = 0;
        const int n = static_cast<int>(s.size());
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && m[s[i]] < m[s[i + 1]]) {
                res -= m[s[i]];
            } else {
                res += m[s[i]];
            }
        }

        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.romanToInt("III") == 3);
    CHECK(s.romanToInt("IV") == 4);
    CHECK(s.romanToInt("IX") == 9);
    CHECK(s.romanToInt("LVIII") == 58);
    CHECK(s.romanToInt("MCMXCIV") == 1994);
}

int main() {
    test();
    return 0;
}
