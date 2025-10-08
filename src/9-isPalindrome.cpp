//
// Created by 1412 on 2025/10/7.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

void test() {
    Solution s;
    assert(s.isPalindrome(121) == true);
    assert(s.isPalindrome(-121) == false);
    assert(s.isPalindrome(10) == false);
}

int main() {
    test();
    return 0;
}
