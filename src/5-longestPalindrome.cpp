//
// Created by 1412 on 2025/9/27.
//

#include <string>
#include <utility>

#include "common.h"


class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::pair<int, int> index{0, 0};
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            auto index1 = findPalindrome(s, i, i);
            auto index2 = findPalindrome(s, i, i + 1);
            index = index1.second - index1.first > index.second - index.first ? index1 : index;
            index = index2.second - index2.first > index.second - index.first ? index2 : index;
        }
        return s.substr(index.first, index.second - index.first + 1);
    }

private:
    static std::pair<int, int> findPalindrome(std::string s, int left, int right) {
        while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};

void test() {
    Solution s;
    CHECK(s.longestPalindrome("babad") == "bab");
    CHECK(s.longestPalindrome("cbbd") == "bb");
    CHECK(s.longestPalindrome("a") == "a");
}

int main() {
    test();
    return 0;
}
