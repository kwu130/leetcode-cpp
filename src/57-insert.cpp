//
// Created by 1412 on 2025/11/4.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        res.reserve(intervals.size() + 1);
        for (auto& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                res.push_back(newInterval);
                newInterval = interval;
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

void test() {
    Solution s;
    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };
    vector<int> newInterval = {2, 5};
    vector<vector<int>> expected = {
        {1, 5},
        {6, 9}
    };
    vector<vector<int>> res = s.insert(intervals, newInterval);
    assert(res == expected);

    intervals = {
        { 1,  2},
        { 3,  5},
        { 6,  7},
        { 8, 10},
        {12, 16}
    };
    newInterval = {4, 8};
    expected = {
        { 1,  2},
        { 3, 10},
        {12, 16}
    };
    res = s.insert(intervals, newInterval);
    assert(res == expected);
}

int main() {
    test();
    return 0;
}
