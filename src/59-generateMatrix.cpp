//
// Created by 1412 on 2025/11/5.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int k = 1;
        int i = 0, j = 0;
        while (k <= n * n) {
            while (j < n && res[i][j] == 0) {
                res[i][j] = k++;
                j++;
            }
            j--;
            i++;
            while (i < n && res[i][j] == 0) {
                res[i][j] = k++;
                i++;
            }
            i--;
            j--;
            while (j >= 0 && res[i][j] == 0) {
                res[i][j] = k++;
                j--;
            }
            j++;
            i--;
            while (i >= 0 && res[i][j] == 0) {
                res[i][j] = k++;
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
    vector<vector<int>> expected = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    vector<vector<int>> res = s.generateMatrix(3);
    assert(res == expected);

    expected = {{1}};
    res = s.generateMatrix(1);
    assert(res == expected);
}

int main() {
    test();
    return 0;
}
