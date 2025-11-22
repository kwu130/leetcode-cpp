//
// Created by 1412 on 2025/11/8.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = static_cast<int>(a.size()) - 1, j = static_cast<int>(b.size()) - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            const int x = i >= 0 ? a[i--] - '0' : 0;
            const int y = j >= 0 ? b[j--] - '0' : 0;
            const int sum = x + y + carry;
            res.push_back(static_cast<char>(sum % 2 + '0'));
            carry = sum / 2;
        }
        ranges::reverse(res);
        return res;
    }
};

void test() {
    Solution s;
    assert(s.addBinary("11", "1") == "100");
    assert(s.addBinary("1010", "1011") == "10101");
    assert(s.addBinary("0", "0") == "0");
}

int main() {
    test();
    return 0;
}
