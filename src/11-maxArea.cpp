//
// Created by 1412 on 2025/10/8.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * std::min(height[i], height[j]);
            res = std::max(res, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    CHECK(s.maxArea(height) == 49);

    height = {1, 1};
    CHECK(s.maxArea(height) == 1);
}

int main() {
    test();
    return 0;
}
