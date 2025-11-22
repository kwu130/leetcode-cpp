//
// Created by 1412 on 2025/11/11.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
    vector<vector<int>> matrix = {
        { 1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    assert(s.searchMatrix(matrix, 3) == true);
    assert(s.searchMatrix(matrix, 13) == false);
}

int main() {
    test();
    return 0;
}
