//
// Created by 1412 on 2026/4/13.
//

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <string>
#include <vector>

#include "common.h"


class Solution {
public:
    std::string decodeString(std::string s) {
        std::vector<std::string> st;
        std::string res;
        for (std::size_t i = 0; i < s.size();) {
            if (std::isdigit(s[i])) {
                std::size_t j = i;
                while (i < s.size() && std::isdigit(s[i])) {
                    i++;
                }
                std::string num = s.substr(j, i - j);
                st.push_back(num);
            } else if (std::isalpha(s[i]) || s[i] == '[') {
                st.emplace_back(1, s[i]);
                i++;
            } else if (s[i] == ']') {
                std::vector<std::string> words;
                while (!st.empty() && st.back() != "[") {
                    words.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back();  // pop '['
                int num = std::stoi(st.back());
                st.pop_back();  // pop num
                std::ranges::reverse(words);
                std::string tmp;
                for (const auto& word : words) {
                    tmp += word;
                }
                std::string repeated_word;
                while (num--) {
                    repeated_word += tmp;
                }
                st.push_back(repeated_word);
                i++;
            }
        }
        for (const auto& word : st) {
            res += word;
        }
        return res;
    }
};

void test() {
    Solution s;
    CHECK(s.decodeString("3[a]2[bc]") == "aaabcbc");
    CHECK(s.decodeString("3[a2[c]]") == "accaccacc");
    CHECK(s.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    CHECK(s.decodeString("abc3[cd]xyz") == "abccdcdcdxyz");
}

int main() {
    test();
    return 0;
}
