//
// Created by 1412 on 2025/10/15.
//

#include <stack>
#include <string>

#include "test_helper.h"


class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (const auto& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                if ((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

void test() {
    Solution s;
    CHECK(s.isValid("()") == true);
    CHECK(s.isValid("()[]{}") == true);
    CHECK(s.isValid("(]") == false);
    CHECK(s.isValid("([])") == true);
    CHECK(s.isValid("([)]") == false);
}

int main() {
    test();
    return 0;
}
