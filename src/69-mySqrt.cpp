//
// Created by 1412 on 2025/11/9.
//


#include "test_helper.h"


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 1, right = x / 2;
        int res = 0;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (mid <= x / mid) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.mySqrt(4) == 2);
    CHECK(s.mySqrt(8) == 2);
}

int main() {
    test();
    return 0;
}
