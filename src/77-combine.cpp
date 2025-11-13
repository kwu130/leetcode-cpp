//
// Created by 1412 on 2025/11/13.
//

#include <bits/stdc++.h>
#include "../include/common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, {}, 1, n, k);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>&& path, int start, int n, int k) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(res, std::move(path), i + 1, n, k);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    vector<vector<int>> expected = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4}
    };
    vector<vector<int>> res = s.combine(4, 2);
    assert(compareHelper::equalIgnoreOrder(res, expected));

    expected = {{1}};
    res = s.combine(1, 1);
    assert(compareHelper::equalIgnoreOrder(res, expected));
}

int main() {
    test();
    return 0;
}
