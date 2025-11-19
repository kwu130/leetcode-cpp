//
// Created by 1412 on 2025/11/19.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n);
        for (int i = 0; i < (1 << n); i++) {
            res[i] = i ^ (i >> 1);
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<int> expect = {0, 1, 3, 2};
    assert(s.grayCode(2) == expect);

    expect = {0, 1};
    assert(s.grayCode(1) == expect);
}

int main() {
    test();
    return 0;
}
