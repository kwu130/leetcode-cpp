//
// Created by 1412 on 2025/12/13.
//

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0),
          left(NULL),
          right(NULL),
          next(NULL) {}

    Node(int _val)
        : val(_val),
          left(NULL),
          right(NULL),
          next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val),
          left(_left),
          right(_right),
          next(_next) {}

    static Node* build(const std::vector<int>& vec, int nullptr_val = -1) {
        if (vec.empty() || vec[0] == nullptr_val) return nullptr;

        std::queue<Node*> q;
        auto* root = new Node(vec[0]);
        q.push(root);

        size_t i = 1;
        while (!q.empty() && i < vec.size()) {
            Node* cur = q.front();
            q.pop();

            if (i < vec.size() && vec[i] != nullptr_val) {
                cur->left = new Node(vec[i]);
                q.push(cur->left);
            }
            i++;

            if (i < vec.size() && vec[i] != nullptr_val) {
                cur->right = new Node(vec[i]);
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }

    static bool equal(Node* lhs, Node* rhs) {
        if (lhs == nullptr && rhs == nullptr) return true;
        if (lhs == nullptr || rhs == nullptr) return false;
        return lhs->val == rhs->val && equal(lhs->left, rhs->left) && equal(lhs->right, rhs->right) &&
               equal(lhs->next, rhs->next);
    }

    static void free(const Node* root) {
        if (root == nullptr) return;
        free(root->left);
        free(root->right);
        delete root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            auto size = q.size();
            for (size_t i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                if (i < size - 1) node->next = q.front();
            }
        }
        return root;
    }
};

void test() {
    Solution s;
    auto root = Node::build({1, 2, 3, 4, 5, 6, 7});
    auto expected = Node::build({1, 2, 3, 4, 5, 6, 7});
    expected->left->next = expected->right;
    expected->left->left->next = expected->left->right;
    expected->left->right->next = expected->right->left;
    expected->right->left->next = expected->right->right;
    root = s.connect(root);
    assert(Node::equal(root, expected));
    free(root);
    free(expected);
    root = Node::build({});
    expected = Node::build({});
    root = s.connect(root);
    assert(Node::equal(root, expected));
    free(root);
    free(expected);
}

int main() {
    test();
    return 0;
}
