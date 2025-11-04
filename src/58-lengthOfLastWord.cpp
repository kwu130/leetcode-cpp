//
// Created by 1412 on 2025/11/4.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
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
    assert(s.lengthOfLastWord("Hello World") == 5);
    assert(s.lengthOfLastWord("   fly me   to   the moon  ") == 4);
    assert(s.lengthOfLastWord("luffy is still joyboy") == 6);
}

int main() {
    test();
    return 0;
}
