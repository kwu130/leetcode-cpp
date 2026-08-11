//
// Created by 1412 on 2025/11/8.
//

#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

void test() {
    Solution s;
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> expected = {1, 2, 4};
    std::vector<int> res = s.plusOne(digits);
    CHECK(res == expected);

    digits = {4, 3, 2, 1};
    expected = {4, 3, 2, 2};
    res = s.plusOne(digits);
    CHECK(res == expected);

    digits = {9};
    expected = {1, 0};
    res = s.plusOne(digits);
    CHECK(res == expected);
}

int main() {
    test();
    return 0;
}
