//
// Created by 1412 on 2025/10/18.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        // special case
        if (dividend == INT_MIN && divisor == INT_MIN) return 1;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN) {
            dividend += abs(divisor);
            res++;
        }
        if (divisor == INT_MIN) return 0;
        const int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            int temp = divisor, m = 1;
            while (dividend >= (temp << 1) && (temp << 1) > 0) {  // fast divide and avoid overflow
                temp <<= 1;
                m <<= 1;
            }
            dividend -= temp;
            res += m;
        }

        return sign * res;
    }
};

void test() {
    Solution s;
    assert(s.divide(10, 3) == 3);
    assert(s.divide(7, -3) == -2);
    assert(s.divide(-2147483648, -2147483648) == 1);
    assert(s.divide(2147483647, 1) == 2147483647);
    assert(s.divide(-2147483648, -1) == 2147483647);
    assert(s.divide(1, -2147483648) == 0);
    assert(s.divide(-2147483648, 2) == -1073741824);
}

int main() {
    test();
    return 0;
}
