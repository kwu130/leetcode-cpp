//
// Created by 1412 on 2025/10/23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, std::move(path), res);
            path.pop_back();
        }
    }
};

void test() {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> expected = {
        {2, 2, 3},
        {7}
    };
    assert(s.combinationSum(candidates, 7) == expected);

    candidates = {2, 3, 5};
    expected = {
        {2, 2, 2, 2},
        {2, 3, 3},
        {3, 5}
    };
    assert(s.combinationSum(candidates, 8) == expected);

    candidates = {2};
    expected = {};
    assert(s.combinationSum(candidates, 1) == expected);
}

int main() {
    test();
    return 0;
}
