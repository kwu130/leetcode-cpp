//
// Created by 1412 on 2025/10/5.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        size_t i = s.find_first_not_of(' ');
        if (i == string::npos) return 0;
        const int sign = s[i] == '-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') i++;
        long res = 0;
        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + (s[i++] - '0');
            if (sign * res < INT_MIN) return INT_MIN;
            if (sign * res > INT_MAX) return INT_MAX;
        }
        return sign * res;
    }
};

void test() {
    Solution s;
    assert(s.myAtoi("42") == 42);
    assert(s.myAtoi("-042") == -42);
    assert(s.myAtoi("1337c0d3") == 1337);
    assert(s.myAtoi("-0-1") == 0);
    assert(s.myAtoi("words and 987") == 0);
}

int main() {
    test();
    return 0;
}
