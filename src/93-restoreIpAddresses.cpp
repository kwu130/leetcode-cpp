//
// Created by 1412 on 2025/11/23.
//

#include <string>
#include <utility>
#include <vector>

#include "compare_helper.h"
#include "test_helper.h"


class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        dfs(s, 0, {}, res);
        return res;
    }

private:
    void dfs(const std::string s, int index, std::vector<std::string>&& path, std::vector<std::string>& res) {
        if (path.size() == 4) {
            if (index == static_cast<int>(s.size())) {
                res.emplace_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }
        for (int l = 1; l <= 3; ++l) {
            if (index + l > static_cast<int>(s.size())) {
                return;
            }
            if (l != 1 && s[index] == '0') {
                return;
            }
            std::string segment = s.substr(index, l);
            if (l == 3 && std::stoi(segment) > 255) {
                return;
            }
            path.push_back(segment);
            dfs(s, index + l, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    std::vector<std::string> expected = {"255.255.11.135", "255.255.111.35"};
    std::vector<std::string> res = s.restoreIpAddresses("25525511135");
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    expected = {"0.0.0.0"};
    res = s.restoreIpAddresses("0000");
    CHECK(compareHelper::equalIgnoreOrder(res, expected));

    expected = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
    res = s.restoreIpAddresses("101023");
    CHECK(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
