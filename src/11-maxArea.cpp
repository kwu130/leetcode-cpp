//
// Created by 1412 on 2025/10/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            res = max(res, area);
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
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(s.maxArea(height) == 49);
    height = {1, 1};
    assert(s.maxArea(height) == 1);
}

int main() {
    test();
    return 0;
}
