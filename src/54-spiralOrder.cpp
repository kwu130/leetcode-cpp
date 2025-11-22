//
// Created by 1412 on 2025/10/31.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        vector<int> res;
        res.reserve(m * n);
        int i = 0, j = 0;
        while (static_cast<int>(res.size()) < m * n) {
            while (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                j++;
            }
            j--;
            i++;
            while (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                i++;
            }
            i--;
            j--;
            while (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                j--;
            }
            j++;
            i--;
            while (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] != INT_MIN) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
                i--;
            }
            i++;
            j++;
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    vector<int> res = s.spiralOrder(matrix);
    assert(res == expected);

    matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    res = s.spiralOrder(matrix);
    assert(res == expected);
}

int main() {
    test();
    return 0;
}
