//
// Created by 1412 on 2025/11/11.
//

#include <vector>

#include "test_helper.h"


class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        int i = 0, j = n - 1;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

void test() {
    Solution s;
    std::vector<std::vector<int>> matrix = {
        { 1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    CHECK(s.searchMatrix(matrix, 3) == true);
    CHECK(s.searchMatrix(matrix, 13) == false);
}

int main() {
    test();
    return 0;
}
