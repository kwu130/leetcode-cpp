//
// Created by 1412 on 2025/11/10.
//

#include <sstream>
#include <string>
#include <vector>

#include "common.h"


class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string res;
        std::istringstream iss(path);
        std::vector<std::string> st;
        std::string str;
        while (std::getline(iss, str, '/')) {
            if (str == "" || str == ".") continue;
            if (str == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(str);
            }
        }
        for (const auto& s : st) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};

void test() {
    Solution s;
    CHECK(s.simplifyPath("/home/") == "/home");
    CHECK(s.simplifyPath("/home//foo/") == "/home/foo");
    CHECK(s.simplifyPath("/home/user/Documents/../Pictures") == "/home/user/Pictures");
    CHECK(s.simplifyPath("/../") == "/");
    CHECK(s.simplifyPath("/.../a/../b/c/../d/./") == "/.../b/d");
}

int main() {
    test();
    return 0;
}
