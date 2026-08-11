//
// Created by 1412 on 2026/4/11.
//

#include <string>
#include <vector>

#include "compare_helper.h"
#include "test_helper.h"


class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    res.push_back(std::to_string(h) + ":" + (m < 10 ? "0" : "") + std::to_string(m));
                }
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    std::vector<std::string> expected = {"0:01", "0:02", "0:04", "0:08", "0:16",
                                         "0:32", "1:00", "2:00", "4:00", "8:00"};
    std::vector<std::string> res = s.readBinaryWatch(1);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    expected = {};
    res = s.readBinaryWatch(9);
    CHECK(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
