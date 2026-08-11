//
// Created by 1412 on 2025/9/29.
//

#include <algorithm>
#include <string>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (s.size() <= 1 || numRows <= 1) {
            return s;
        }
        std::vector<std::vector<char>> m(numRows);
        for (int i = 0, row = 0, dir = 1; i < static_cast<int>(s.size()); i++) {
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
        std::string res;
        for (auto& str : m) {
            std::ranges::for_each(str, [&res](const char c) { res += c; });
        }
        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CHECK(s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CHECK(s.convert("A", 1) == "A");
}

int main() {
    test();
    return 0;
}
