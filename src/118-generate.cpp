//
// Created by 1412 on 2025/12/17.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows == 0) return result;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Create row i with all values initialized to 1
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
    auto expected = vector<vector<int>>({
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    });
    assert(res == expected);
    res = s.generate(1);
    expected = vector<vector<int>>({{1}});
    assert(res == expected);
    res = s.generate(0);
    expected = vector<vector<int>>();
    assert(res == expected);
}

int main() {
    test();
    return 0;
}
