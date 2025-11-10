//
// Created by 1412 on 2025/11/10.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        istringstream iss(path);
        vector<string> st;
        string str;
        while (getline(iss, str, '/')) {
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
    assert(s.simplifyPath("/home/") == "/home");
    assert(s.simplifyPath("/home//foo/") == "/home/foo");
    assert(s.simplifyPath("/home/user/Documents/../Pictures") == "/home/user/Pictures");
    assert(s.simplifyPath("/../") == "/");
    assert(s.simplifyPath("/.../a/../b/c/../d/./") == "/.../b/d");
}

int main() {
    test();
    return 0;
}
