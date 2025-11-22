//
// Created by 1412 on 2025/10/24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        ranges::sort(candidates);
        dfs(candidates, target, 0, {}, res);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>&& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.emplace_back(path);
            return;
        }
        for (int i = index; i < static_cast<int>(candidates.size()); i++) {
            if (candidates[i] > target) break;
            if (i > index && candidates[i] == candidates[i - 1]) continue;  // 剪枝 重点理解这个 i>index 的作用
            path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> expected = {
        {1, 1, 6},
        {1, 2, 5},
        {1, 7},
        {2, 6}
    };
    assert(s.combinationSum2(candidates, 8) == expected);

    candidates = {2, 5, 2, 1, 2};
    expected = {
        {1, 2, 2},
        {5}
    };
    assert(s.combinationSum2(candidates, 5) == expected);
}

int main() {
    test();
    return 0;
}
