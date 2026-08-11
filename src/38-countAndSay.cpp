//
// Created by 1412 on 2025/10/23.
//

#include <string>
#include <utility>

#include "test_helper.h"


class Solution {
public:
    std::string countAndSay(int n) {
        std::string res = "1";
        while (--n) {
            std::string tmp;
            const int m = static_cast<int>(res.size());
            for (int i = 0; i < m; ++i) {
                int cnt = 1;
                while (i < m - 1 && res[i] == res[i + 1]) {
                    cnt++;
                    i++;
                }
                tmp = tmp + std::to_string(cnt) + res[i];
            }
            res = std::move(tmp);
        }

        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.countAndSay(4) == "1211");
    CHECK(s.countAndSay(1) == "1");
}

int main() {
    test();
    return 0;
}
