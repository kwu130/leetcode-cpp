//
// Created by 1412 on 2026/10/30.
//

#include <bits/stdc++.h>

#include "common.h"

using namespace std;

class Solution {
public:
    int rand10() {
        int num;
        do {
            num = (rand7() - 1) * 7 + rand7() - 1;
        } while (num >= 40);
        return num % 10 + 1;
    }

private:
    static int rand7() { return rand() % 7 + 1; }
};

void test() {
    Solution s;
    srand(0);

    constexpr int sampleCount = 100000;
    constexpr int expectedCount = sampleCount / 10;
    int counts[10] = {0};
    for (int i = 0; i < sampleCount; i++) {
        int value = s.rand10();
        CHECK(value >= 1 && value <= 10);
        counts[value - 1]++;
    }

    // 随机结果不检查具体值，允许各数字的出现次数与期望值有 10% 的偏差。
    for (int count : counts) {
        CHECK(abs(count - expectedCount) <= expectedCount / 10);
    }
}

int main() {
    test();
    return 0;
}
