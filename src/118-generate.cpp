//
// Created by 1412 on 2025/12/17.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;

        if (numRows == 0) return result;

        for (int i = 0; i < numRows; i++) {
            std::vector<int> row(i + 1, 1);  // Create row i with all values initialized to 1
            // Calculate middle values
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }

        return result;
    }
};

void test() {
    Solution s;
    auto res = s.generate(5);
    auto expected = std::vector<std::vector<int>>({
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    });
    CHECK(res == expected);
    res = s.generate(1);
    expected = std::vector<std::vector<int>>({{1}});
    CHECK(res == expected);
    res = s.generate(0);
    expected = std::vector<std::vector<int>>();
    CHECK(res == expected);
}

int main() {
    test();
    return 0;
}
