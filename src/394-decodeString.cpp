//
// Created by 1412 on 2026/4/13.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        string res;
        for (size_t i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                size_t j = i;
                while (i < s.size() && isdigit(s[i])) {
                    i++;
                }
                string num = s.substr(j, i - j);
                st.push_back(num);
            } else if (isalpha(s[i]) || s[i] == '[') {
                st.emplace_back(1, s[i]);
                i++;
            } else if (s[i] == ']') {
                vector<string> words;
                while (!st.empty() && st.back() != "[") {
                    words.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back();  // pop '['
                int num = stoi(st.back());
                st.pop_back();  // pop num
                ranges::reverse(words);
                string tmp;
                for (const auto& word : words) {
                    tmp += word;
                }
                string repeated_word;
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
    assert(s.decodeString("3[a]2[bc]") == "aaabcbc");
    assert(s.decodeString("3[a2[c]]") == "accaccacc");
    assert(s.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    assert(s.decodeString("abc3[cd]xyz") == "abccdcdcdxyz");
}

int main() {
    test();
    return 0;
}
