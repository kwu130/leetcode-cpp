//
// Created by 1412 on 2026/10/26.
//

#include <bits/stdc++.h>

#include "common.h"

using namespace std;

class Solution {
public:
    /*
     * 假设 sum = a[0] + a[1] + a[2] + ... + a[n-1]
     * f(0) = 0 * a[0]   + 1 * a[1] + 2 * a[2] + ... + (n-1) * a[n-1]
     * f(1) = 0 * a[n-1] + 1 * a[0] + 2 * a[1] + ... + (n-1) * a[n-2]
     * f(1) = f(0) + a[0] + a[1] + a[2] + ... + a[n-2] - (n-1) * a[n-1]
     *      = f(0) + a[0] + a[1] + a[2] + ... + a[n-2] + (a[n-1] - a[n-1]) - (n-1) * a[n-1]
     *      = f(0) + a[0] + a[1] + a[2] + ... + a[n-2] + a[n-1] - n * a[n-1]
     *      = f(0) + sum - n * a[n-1]
     * 所以 f(2) = f(1) + sum - n * a[n-2]
     *     f(3) = f(2) + sum - n * a[n-3]
     *     ...
     *     f(n-1) = f(n-2) + sum - n * a[1]
     * 所以 res = max(f(0), f(1), f(2), ... f(n-1))
     */
    int maxRotateFunction(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        const long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        long long f = 0;
        for (int i = 0; i < n; i++) {
            f += 1LL * i * nums[i];
        }

        long long res = f;
        for (int i = n - 1; i > 0; i--) {
            f = f + sum - 1LL * n * nums[i];
            res = max(res, f);
        }

        return static_cast<int>(res);
    }
};

void test() {
    Solution s;
    vector<int> nums = {4, 3, 2, 6};
    CHECK(s.maxRotateFunction(nums) == 26);

    nums = {100};
    CHECK(s.maxRotateFunction(nums) == 0);

    nums = {-1, 1};
    CHECK(s.maxRotateFunction(nums) == 1);

    nums = {1, -1};
    CHECK(s.maxRotateFunction(nums) == 1);

    nums = {-2, -1};
    CHECK(s.maxRotateFunction(nums) == -1);
}

int main() {
    test();
    return 0;
}
