//
// Created by 1412 on 2025/10/23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) {
            string tmp;
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i < res.size() - 1 && res[i] == res[i + 1]) {
                    cnt++;
                    i++;
                }
                tmp = tmp + to_string(cnt) + res[i];
            }
            res = std::move(tmp);
        }

        return res;
    }
};

void test() {
    Solution s;
    assert(s.countAndSay(4) == "1211");
    assert(s.countAndSay(1) == "1");
}

int main() {
    test();
    return 0;
}
