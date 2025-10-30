//
// Created by 1412 on 2025/10/30.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) { return myPowImpl(x, n); }

private:
    static double myPowImpl(const double x, const long n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / myPowImpl(x, -n);
        if (n % 2 == 1) {
            return x * myPowImpl(x, n - 1);
        }
        return myPowImpl(x * x, n / 2);
    }
};

void test() {
    Solution s;
    assert(abs(s.myPow(2.0, 10) - 1024.0) < 1e-9);
    assert(abs(s.myPow(2.1, 3) - 9.261) < 1e-9);
    assert(abs(s.myPow(2.0, -2) - 0.25) < 1e-9);
}

int main() {
    test();
    return 0;
}
