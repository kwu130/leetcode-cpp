//
// Created by 1412 on 2026/4/12.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;
        int d = 1;
        while (n > 1) {
            start = start + (n - 1 - (n % 2)) * d;
            d *= -2;
            n /= 2;
        }
        return start;
    }
};

void test() {
    Solution s;
    CHECK(s.lastRemaining(9) == 6);
    CHECK(s.lastRemaining(1) == 1);
}

int main() {
    test();
    return 0;
}
