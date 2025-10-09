//
// Created by 1412 on 2025/10/9.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> hash(4);
        hash[0] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        hash[1] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        hash[2] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        hash[3] = {"", "M", "MM", "MMM"};
        return hash[3][num / 1000] + hash[2][(num % 1000) / 100] + hash[1][(num % 100) / 10] + hash[0][num % 10];
    }
};

void test() {
    Solution s;
    assert(s.intToRoman(3749) == "MMMDCCXLIX");
    assert(s.intToRoman(58) == "LVIII");
    assert(s.intToRoman(1994) == "MCMXCIV");
}

int main() {
    test();
    return 0;
}
