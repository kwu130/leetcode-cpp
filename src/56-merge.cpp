//
// Created by 1412 on 2025/11/3.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.emplace_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    vector<vector<int>> intervals = {
        { 1,  3},
        { 2,  6},
        { 8, 10},
        {15, 18}
    };
    vector<vector<int>> expect = {
        { 1,  6},
        { 8, 10},
        {15, 18}
    };
    vector<vector<int>> res = s.merge(intervals);
    assert(res == expect);

    intervals = {
        {1, 4},
        {4, 5}
    };
    expect = {
        {1, 5}
    };
    res = s.merge(intervals);
    assert(res == expect);

    intervals = {
        {4, 7},
        {1, 4}
    };
    expect = {
        {1, 7}
    };
    res = s.merge(intervals);
    assert(res == expect);
}

int main() {
    test();
    return 0;
}
