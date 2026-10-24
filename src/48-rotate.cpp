//
// Created by 1412 on 2025/10/28.
//

#include <algorithm>
#include <utility>
#include <vector>

#include "common.h"


class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);  // 转置
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                std::swap(matrix[i][j], matrix[i][n - j - 1]);  // 镜像
            }
        }
    }
};

void test() {
    Solution s;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> expected = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    s.rotate(matrix);
    CHECK(matrix == expected);

    matrix = {
        { 5,  1,  9, 11},
        { 2,  4,  8, 10},
        {13,  3,  6,  7},
        {15, 14, 12, 16}
    };
    expected = {
        {15, 13,  2,  5},
        {14,  3,  4,  1},
        {12,  6,  8,  9},
        {16,  7, 10, 11}
    };
    s.rotate(matrix);
    CHECK(matrix == expected);
}

int main() {
    test();
    return 0;
}
