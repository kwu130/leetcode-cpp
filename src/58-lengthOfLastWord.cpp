//
// Created by 1412 on 2025/11/4.
//

#include <string>

#include "common.h"


class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.find_last_not_of(' ');
        int res = 0;
        while (i >= 0 && s[i--] != ' ') {
            res++;
        }
        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.lengthOfLastWord("Hello World") == 5);
    CHECK(s.lengthOfLastWord("   fly me   to   the moon  ") == 4);
    CHECK(s.lengthOfLastWord("luffy is still joyboy") == 6);
}

int main() {
    test();
    return 0;
}
