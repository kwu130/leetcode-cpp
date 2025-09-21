//
// Created by 1412 on 2025/9/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        stack<pair<int, int>> s;
        s.emplace(-1, 0);  // 栈顶元素为当前路径的深度和当前路径的长度 设置哨兵元素
        istringstream iss(input);
        string token;
        auto is_file = [](const string& s) { return ranges::find(s, '.') != s.end(); };
        while (getline(iss, token, '\n')) {
            int depth = ranges::count(token, '\t');
            erase(token, '\t');
            while (depth <= s.top().first) {
                s.pop();  // 保证栈顶元素的深度小于当前元素
            }
            if (is_file(token)) {
                res = max(res, s.top().second + static_cast<int>(token.size()));
            } else {
                s.emplace(depth, s.top().second + static_cast<int>(token.size()) + 1);  // +1 是因为路径中的/
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    assert(s.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") == 20);
    assert(s.lengthLongestPath(
               "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") == 32);
    assert(s.lengthLongestPath("a") == 0);
    assert(s.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt") == 12);
}

int main() {
    test();
    return 0;
}
