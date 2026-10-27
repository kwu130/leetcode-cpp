//
// Created by 1412 on 2026/4/11.
//

#include <bits/stdc++.h>

#include "common.h"


class NestedInteger {
private:
    bool is_int;
    int integer_value;
    std::vector<NestedInteger> list_value;

public:
    // Constructor initializes an empty nested list.
    NestedInteger()
        : is_int(false),
          integer_value(0) {}

    // Constructor initializes a single integer.
    explicit NestedInteger(int value)
        : is_int(true),
          integer_value(value) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return is_int; }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return integer_value; }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        is_int = true;
        integer_value = value;
        list_value.clear();
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni) {
        is_int = false;
        list_value.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger>& getList() const { return list_value; }
};

class Solution {
public:
    NestedInteger deserialize(std::string s) {
        if (s[0] != '[') {
            return NestedInteger(std::stoi(s));
        }
        std::stack<NestedInteger> st;
        std::size_t start = 0;  // the start index of a number
        for (std::size_t i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '[':
                    st.emplace(NestedInteger());
                    start = i + 1;
                    break;
                case ',':
                    if (i > start) {
                        const int num = std::stoi(s.substr(start, i - start));
                        st.top().add(NestedInteger(num));
                    }
                    start = i + 1;
                    break;
                case ']':
                    NestedInteger topped = st.top();
                    st.pop();
                    if (i > start) {
                        const int num = std::stoi(s.substr(start, i - start));
                        topped.add(NestedInteger(num));
                    }
                    if (!st.empty()) {
                        st.top().add(topped);
                    } else {
                        return topped;
                    }
                    start = i + 1;
                    break;
            }
        }
        throw;
    }
};

// Helper function to print NestedInteger
void printNestedInteger(const NestedInteger& ni, int indent = 0) {
    if (ni.isInteger()) {
        std::cout << std::string(indent * 2, ' ') << "Integer: " << ni.getInteger() << std::endl;
    } else {
        std::cout << std::string(indent * 2, ' ') << "List: [" << std::endl;
        for (const auto& item : ni.getList()) {
            printNestedInteger(item, indent + 1);
        }
        std::cout << std::string(indent * 2, ' ') << "]" << std::endl;
    }
}

// Helper function to compare two NestedIntegers
bool equalNestedInteger(const NestedInteger& a, const NestedInteger& b) {
    if (a.isInteger() != b.isInteger()) {
        return false;
    }

    if (a.isInteger()) {
        return a.getInteger() == b.getInteger();
    }

    const auto& listA = a.getList();
    const auto& listB = b.getList();

    if (listA.size() != listB.size()) {
        return false;
    }

    for (std::size_t i = 0; i < listA.size(); ++i) {
        if (!equalNestedInteger(listA[i], listB[i])) {
            return false;
        }
    }

    return true;
}

void test() {
    Solution s;

    // Test case 1: Simple integer
    {
        std::string input = "324";
        NestedInteger result = s.deserialize(input);
        CHECK(result.isInteger());
        CHECK(result.getInteger() == 324);
        std::cout << "Test 1 passed: " << input << std::endl;
    }

    // Test case 2: Simple list [1,2,3]
    {
        std::string input = "[1,2,3]";
        NestedInteger result = s.deserialize(input);
        CHECK(!result.isInteger());
        const auto& list = result.getList();
        CHECK(list.size() == 3);
        CHECK(list[0].isInteger() && list[0].getInteger() == 1);
        CHECK(list[1].isInteger() && list[1].getInteger() == 2);
        CHECK(list[2].isInteger() && list[2].getInteger() == 3);
        std::cout << "Test 2 passed: " << input << std::endl;
    }

    // Test case 3: Nested list [1,[4,[6]]]
    {
        std::string input = "[1,[4,[6]]]";
        NestedInteger result = s.deserialize(input);
        CHECK(!result.isInteger());
        const auto& list = result.getList();
        CHECK(list.size() == 2);
        CHECK(list[0].isInteger() && list[0].getInteger() == 1);

        // Check nested structure: [4,[6]] has 2 elements
        CHECK(!list[1].isInteger());
        const auto& nested1 = list[1].getList();
        CHECK(nested1.size() == 2);
        CHECK(nested1[0].isInteger() && nested1[0].getInteger() == 4);

        // Check deeply nested: [6]
        CHECK(!nested1[1].isInteger());
        const auto& nested2 = nested1[1].getList();
        CHECK(nested2.size() == 1);
        CHECK(nested2[0].isInteger() && nested2[0].getInteger() == 6);

        std::cout << "Test 3 passed: " << input << std::endl;
    }

    // Test case 4: Complex nested list [[1,1],2,[1,1]]
    {
        std::string input = "[[1,1],2,[1,1]]";
        NestedInteger result = s.deserialize(input);
        CHECK(!result.isInteger());
        const auto& list = result.getList();
        CHECK(list.size() == 3);

        // First element: [1,1]
        CHECK(!list[0].isInteger());
        const auto& first = list[0].getList();
        CHECK(first.size() == 2);
        CHECK(first[0].getInteger() == 1);
        CHECK(first[1].getInteger() == 1);

        // Second element: 2
        CHECK(list[1].isInteger() && list[1].getInteger() == 2);

        // Third element: [1,1]
        CHECK(!list[2].isInteger());
        const auto& third = list[2].getList();
        CHECK(third.size() == 2);
        CHECK(third[0].getInteger() == 1);
        CHECK(third[1].getInteger() == 1);

        std::cout << "Test 4 passed: " << input << std::endl;
    }

    // Test case 5: Empty list []
    {
        std::string input = "[]";
        NestedInteger result = s.deserialize(input);
        CHECK(!result.isInteger());
        CHECK(result.getList().empty());
        std::cout << "Test 5 passed: " << input << std::endl;
    }

    // Test case 6: Negative numbers [-1,-2,-3]
    {
        std::string input = "[-1,-2,-3]";
        NestedInteger result = s.deserialize(input);
        CHECK(!result.isInteger());
        const auto& list = result.getList();
        CHECK(list.size() == 3);
        CHECK(list[0].getInteger() == -1);
        CHECK(list[1].getInteger() == -2);
        CHECK(list[2].getInteger() == -3);
        std::cout << "Test 6 passed: " << input << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test();
    return 0;
}
