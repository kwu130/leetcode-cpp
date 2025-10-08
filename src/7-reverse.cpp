//
// Created by 1412 on 2025/9/29.
//

#include <bits/stdc++.h>

using namespace std;

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
    assert(s.reverse(123) == 321);
    assert(s.reverse(-123) == -321);
    assert(s.reverse(120) == 21);
    assert(s.reverse(0) == 0);
    assert(s.reverse(-2147483412) == -2143847412);
}

int main() {
    test();
    return 0;
}
