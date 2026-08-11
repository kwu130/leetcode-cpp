//
// Created by 1412 on 2025/12/17.
//

#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1);  // Create row with all values initialized to 1

        // Calculate from row 1 to rowIndex
        for (int i = 1; i <= rowIndex; i++) {
            // Update from right to left to avoid overwriting values we need
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};

void test() {
    Solution s;
    auto res = s.getRow(3);
    auto expected = std::vector<int>({1, 3, 3, 1});
    CHECK(res == expected);
    res = s.getRow(0);
    expected = std::vector<int>({1});
    CHECK(res == expected);
    res = s.getRow(1);
    expected = std::vector<int>({1, 1});
    CHECK(res == expected);
    res = s.getRow(4);
    expected = std::vector<int>({1, 4, 6, 4, 1});
    CHECK(res == expected);
}

int main() {
    test();
    return 0;
}
