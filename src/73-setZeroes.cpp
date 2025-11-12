//
// Created by 1412 on 2025/11/11.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        const int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                row0 = true;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (col0) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

void test() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    vector<vector<int>> expected = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };
    s.setZeroes(matrix);
    assert(matrix == expected);

    matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    expected = {
        {0, 0, 0, 0},
        {0, 4, 5, 0},
        {0, 3, 1, 0}
    };
    s.setZeroes(matrix);
    assert(matrix == expected);
}

int main() {
    test();
    return 0;
}
