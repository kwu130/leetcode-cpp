//
// Created by 1412 on 2026/10/25.
//

#include <algorithm>
#include <string>
#include <vector>

#include "test_helper.h"

using namespace std;

class Solution {
public:
    /*
     * 具体步骤：
     * 1. 统计当前区间每个字符的频次。
     * 2. 如果所有字符的频次都至少为 k，直接返回整个区间的长度。
     * 3. 否则，用频次小于 k 的字符分割区间，递归求各段的答案，取最大值。
     * 4. 区间长度小于 k 时，直接返回 0。
     * 注意：每次递归都要重新统计当前区间的频次，因为原本满足条件的字符，分割后可能不再满足。
     * 时间复杂度：O(26n)
     * 空间复杂度：O(1)
     */
    int longestSubstring(string s, int k) { return dfs(s, 0, s.length(), k); }

private:
    int dfs(string s, int l, int r, int k) {
        if (r - l < k) return 0;  // 总字符数小于 k

        vector<int> count(26);
        for (int i = l; i < r; i++) {
            count[s[i] - 'a']++;
        }

        int res = 0;
        int start = l;
        for (int i = l; i < r; i++) {
            if (count[s[i] - 'a'] >= k) {
                continue;
            }
            // s[i] 不能出现在合法子串中，递归处理它前面的一段
            res = max(res, dfs(s, start, i, k));
            start = i + 1;
        }

        // 没有遇到分隔符，整个区间都合法
        if (start == l) {
            return r - l;
        }

        // 处理最后一个区间
        return max(res, dfs(s, start, r, k));
    }
};

void test() {
    Solution s;
    CHECK(s.longestSubstring("aaabb", 3) == 3);
    CHECK(s.longestSubstring("ababbc", 2) == 5);
}


int main() {
    test();
    return 0;
}
