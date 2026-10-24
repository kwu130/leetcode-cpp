//
// Created by 1412 on 2025/11/3.
//

#include <algorithm>
#include <vector>

#include "common.h"


class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::ranges::sort(intervals);
        std::vector<std::vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.emplace_back(interval);
            } else {
                res.back()[1] = std::max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

void test() {
    Solution s;
    std::vector<std::vector<int>> intervals = {
        { 1,  3},
        { 2,  6},
        { 8, 10},
        {15, 18}
    };
    std::vector<std::vector<int>> expect = {
        { 1,  6},
        { 8, 10},
        {15, 18}
    };
    std::vector<std::vector<int>> res = s.merge(intervals);
    CHECK(res == expect);

    intervals = {
        {1, 4},
        {4, 5}
    };
    expect = {
        {1, 5}
    };
    res = s.merge(intervals);
    CHECK(res == expect);

    intervals = {
        {4, 7},
        {1, 4}
    };
    expect = {
        {1, 7}
    };
    res = s.merge(intervals);
    CHECK(res == expect);
}

int main() {
    test();
    return 0;
}
