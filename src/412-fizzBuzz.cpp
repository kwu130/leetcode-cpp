//
// Created by 1412 on 2026/10/24.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                res[i] = "FizzBuzz";
            } else if (i % 3 == 0) {
                res[i] = "Fizz";
            } else if (i % 5 == 0) {
                res[i] = "Buzz";
            } else {
                res[i] = to_string(i);
            }
        }
        return {res.begin() + 1, res.end()};
    }
};

void test() {
    Solution s;
    vector<string> expected = {"1", "2", "Fizz"};
    vector<string> res = s.fizzBuzz(3);
    assert(res == expected);

    expected = {"1", "2", "Fizz", "4", "Buzz"};
    res = s.fizzBuzz(5);
    assert(res == expected);

    expected = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};
    res = s.fizzBuzz(15);
    assert(res == expected);
}

int main() {
    test();
    return 0;
}
