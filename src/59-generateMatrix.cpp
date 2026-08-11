//
// Created by 1412 on 2025/11/5.
//

#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
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
    std::vector<std::vector<int>> expected = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    std::vector<std::vector<int>> res = s.generateMatrix(3);
    CHECK(res == expected);

    expected = {{1}};
    res = s.generateMatrix(1);
    CHECK(res == expected);
}

int main() {
    test();
    return 0;
}
