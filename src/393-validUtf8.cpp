//
// Created by 1412 on 2026/4/13.
//

#include <cstddef>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    bool validUtf8(std::vector<int>& data) {
        for (std::size_t i = 0; i < data.size(); ++i) {
            if (data[i] >> 7 == 0b0) {
                continue;
            }
            if (data[i] >> 5 == 0b110) {
                if (i + 1 < data.size() && data[i + 1] >> 6 == 0b10) {
                    i++;
                    continue;
                }
            }
            if (data[i] >> 4 == 0b1110) {
                if (i + 2 < data.size() && data[i + 1] >> 6 == 0b10 && data[i + 2] >> 6 == 0b10) {
                    i += 2;
                    continue;
                }
            }
            if (data[i] >> 3 == 0b11110) {
                if (i + 3 < data.size() && data[i + 1] >> 6 == 0b10 && data[i + 2] >> 6 == 0b10 &&
                    data[i + 3] >> 6 == 0b10) {
                    i += 3;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};

void test() {
    Solution s;
    std::vector<int> data = {197, 130, 1};
    CHECK(s.validUtf8(data) == true);
    data = {235, 140, 4};
    CHECK(s.validUtf8(data) == false);
    data = {237};
    CHECK(s.validUtf8(data) == false);
}

int main() {
    test();
    return 0;
}
