//
// Created by 1412 on 2025/9/29.
//

#include <algorithm>
#include <climits>

#include "common.h"


class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.reverse(123) == 321);
    CHECK(s.reverse(-123) == -321);
    CHECK(s.reverse(120) == 21);
    CHECK(s.reverse(0) == 0);
    CHECK(s.reverse(-2147483412) == -2143847412);
}

int main() {
    test();
    return 0;
}
