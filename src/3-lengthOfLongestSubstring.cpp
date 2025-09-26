//
// Created by 1412 on 2025/9/26.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char chs[128] = {0};
        int res = 0;
        for (int left = 0, right = 0; right < s.size(); right++) {
            chs[s[right]]++;
            while (chs[s[right]] > 1) {
                chs[s[left++]]--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

void test() {
    Solution s;
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
}

int main() {
    test();
    return 0;
}
