//
// Created by 1412 on 2025/9/29.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= 1 || numRows <= 1) {
            return s;
        }
        vector<vector<char>> m(numRows);
        for (int i = 0, row = 0, dir = 1; i < s.size(); i++) {
            if (dir == 1) {
                m[row++].push_back(s[i]);
            } else {
                m[row--].push_back(s[i]);
            }
            if (row == numRows) {
                row = numRows - 2;
                dir = -1;
            } else if (row == -1) {
                row = 1;
                dir = 1;
            }
        }
        string res;
        for (auto& str : m) {
            ranges::for_each(str, [&res](const char c) { res += c; });
        }
        return res;
    }
};

void test() {
    Solution s;
    assert(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(s.convert("A", 1) == "A");
}

int main() {
    test();
    return 0;
}
