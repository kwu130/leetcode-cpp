//
// Created by 1412 on 2025/11/4.
//

#include <algorithm>
#include <vector>

#include "test_helper.h"


class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> res;
        res.reserve(intervals.size() + 1);
        for (auto& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                res.push_back(newInterval);
                newInterval = interval;
            } else {
                newInterval[0] = std::min(newInterval[0], interval[0]);
                newInterval[1] = std::max(newInterval[1], interval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

void test() {
    Solution s;
    std::vector<std::vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };
    std::vector<int> newInterval = {2, 5};
    std::vector<std::vector<int>> expected = {
        {1, 5},
        {6, 9}
    };
    std::vector<std::vector<int>> res = s.insert(intervals, newInterval);
    CHECK(res == expected);

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
    CHECK(res == expected);
}

int main() {
    test();
    return 0;
}
