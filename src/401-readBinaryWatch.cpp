//
// Created by 1412 on 2026/4/11.
//

#include <bits/stdc++.h>
#include "common.h"

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<string> expected = {"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};
    vector<string> res = s.readBinaryWatch(1);
    assert(compareHelper::equalIgnoreOrder(res, expected));

    expected = {};
    res = s.readBinaryWatch(9);
    assert(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
