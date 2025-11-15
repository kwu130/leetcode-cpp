//
// Created by 1412 on 2025/11/15.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        vector<vector<bool>> search(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, search, "")) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, vector<vector<bool>>& search, string&& path) {
        if (path == word) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || search[i][j] ||
            board[i][j] != word[path.size()]) {
            return false;
        }
        search[i][j] = true;
        path += board[i][j];
        if (dfs(board, word, i - 1, j, search, std::move(path)) ||
            dfs(board, word, i + 1, j, search, std::move(path)) ||
            dfs(board, word, i, j - 1, search, std::move(path)) ||
            dfs(board, word, i, j + 1, search, std::move(path))) {
            return true;
        }
        search[i][j] = false;
        path.pop_back();
        return false;
    }
};

void test() {
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    assert(s.exist(board, "ABCCED") == true);
    assert(s.exist(board, "SEE") == true);
    assert(s.exist(board, "ABCB") == false);

    board = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };
    assert(s.exist(board, "AAB") == true);
}

int main() {
    test();
    return 0;
}
