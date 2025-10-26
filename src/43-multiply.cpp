//
// Created by 1412 on 2025/10/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                const int mult = (num1[i] - '0') * (num2[j] - '0');
                const int sum = mult + (res[i + j + 1] - '0');
                res[i + j + 1] = (sum % 10) + '0';
                res[i + j] += sum / 10;
            }
        }
        const int idx = res.find_first_not_of('0');
        return idx == string::npos ? "0" : res.substr(idx);
    }
};

void test() {
    Solution s;
    assert(s.multiply("2", "3") == "6");
    assert(s.multiply("123", "456") == "56088");
}

int main() {
    test();
    return 0;
}
