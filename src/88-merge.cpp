//
// Created by 1412 on 2025/11/19.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

void test() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    vector<int> expected = {1, 2, 2, 3, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    assert(nums1 == expected);

    nums1 = {1};
    nums2 = {};
    expected = {1};
    s.merge(nums1, 1, nums2, 0);
    assert(nums1 == expected);

    nums1 = {0};
    nums2 = {1};
    expected = {1};
    s.merge(nums1, 0, nums2, 1);
    assert(nums1 == expected);
}

int main() {
    test();
    return 0;
}
