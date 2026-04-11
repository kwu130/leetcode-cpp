//
// Created by 1412 on 2026/4/11.
//

#include <bits/stdc++.h>

using namespace std;

class NestedInteger {
private:
    bool is_int;
    int integer_value;
    vector<NestedInteger> list_value;

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
    const vector<NestedInteger>& getList() const { return list_value; }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> st;
        size_t start = 0;  // the start index of a number
        for (size_t i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '[':
                    st.emplace(NestedInteger());
                    start = i + 1;
                    break;
                case ',':
                    if (i > start) {
                        const int num = stoi(s.substr(start, i - start));
                        st.top().add(NestedInteger(num));
                    }
                    start = i + 1;
                    break;
                case ']':
                    NestedInteger topped = st.top();
                    st.pop();
                    if (i > start) {
                        const int num = stoi(s.substr(start, i - start));
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
        cout << string(indent * 2, ' ') << "Integer: " << ni.getInteger() << endl;
    } else {
        cout << string(indent * 2, ' ') << "List: [" << endl;
        for (const auto& item : ni.getList()) {
            printNestedInteger(item, indent + 1);
        }
        cout << string(indent * 2, ' ') << "]" << endl;
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

    for (size_t i = 0; i < listA.size(); ++i) {
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
        string input = "324";
        NestedInteger result = s.deserialize(input);
        assert(result.isInteger());
        assert(result.getInteger() == 324);
        cout << "Test 1 passed: " << input << endl;
    }

    // Test case 2: Simple list [1,2,3]
    {
        string input = "[1,2,3]";
        NestedInteger result = s.deserialize(input);
        assert(!result.isInteger());
        const auto& list = result.getList();
        assert(list.size() == 3);
        assert(list[0].isInteger() && list[0].getInteger() == 1);
        assert(list[1].isInteger() && list[1].getInteger() == 2);
        assert(list[2].isInteger() && list[2].getInteger() == 3);
        cout << "Test 2 passed: " << input << endl;
    }

    // Test case 3: Nested list [1,[4,[6]]]
    {
        string input = "[1,[4,[6]]]";
        NestedInteger result = s.deserialize(input);
        assert(!result.isInteger());
        const auto& list = result.getList();
        assert(list.size() == 2);
        assert(list[0].isInteger() && list[0].getInteger() == 1);

        // Check nested structure: [4,[6]] has 2 elements
        assert(!list[1].isInteger());
        const auto& nested1 = list[1].getList();
        assert(nested1.size() == 2);
        assert(nested1[0].isInteger() && nested1[0].getInteger() == 4);

        // Check deeply nested: [6]
        assert(!nested1[1].isInteger());
        const auto& nested2 = nested1[1].getList();
        assert(nested2.size() == 1);
        assert(nested2[0].isInteger() && nested2[0].getInteger() == 6);

        cout << "Test 3 passed: " << input << endl;
    }

    // Test case 4: Complex nested list [[1,1],2,[1,1]]
    {
        string input = "[[1,1],2,[1,1]]";
        NestedInteger result = s.deserialize(input);
        assert(!result.isInteger());
        const auto& list = result.getList();
        assert(list.size() == 3);

        // First element: [1,1]
        assert(!list[0].isInteger());
        const auto& first = list[0].getList();
        assert(first.size() == 2);
        assert(first[0].getInteger() == 1);
        assert(first[1].getInteger() == 1);

        // Second element: 2
        assert(list[1].isInteger() && list[1].getInteger() == 2);

        // Third element: [1,1]
        assert(!list[2].isInteger());
        const auto& third = list[2].getList();
        assert(third.size() == 2);
        assert(third[0].getInteger() == 1);
        assert(third[1].getInteger() == 1);

        cout << "Test 4 passed: " << input << endl;
    }

    // Test case 5: Empty list []
    {
        string input = "[]";
        NestedInteger result = s.deserialize(input);
        assert(!result.isInteger());
        assert(result.getList().empty());
        cout << "Test 5 passed: " << input << endl;
    }

    // Test case 6: Negative numbers [-1,-2,-3]
    {
        string input = "[-1,-2,-3]";
        NestedInteger result = s.deserialize(input);
        assert(!result.isInteger());
        const auto& list = result.getList();
        assert(list.size() == 3);
        assert(list[0].getInteger() == -1);
        assert(list[1].getInteger() == -2);
        assert(list[2].getInteger() == -3);
        cout << "Test 6 passed: " << input << endl;
    }

    cout << "All tests passed!" << endl;
}

int main() {
    test();
    return 0;
}
