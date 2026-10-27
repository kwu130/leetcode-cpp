//
// Created by 1412 on 2025/11/15.
//

#include <bits/stdc++.h>

#include "common.h"


class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        const int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> search(m, std::vector<bool>(n, false));
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
    bool dfs(std::vector<std::vector<char>>& board,
             std::string& word,
             int i,
             int j,
             std::vector<std::vector<bool>>& search,
             std::string&& path) {
        if (path == word) {
            return true;
        }
        if (i < 0 || i >= static_cast<int>(board.size()) || j < 0 || j >= static_cast<int>(board[0].size()) ||
            search[i][j] || board[i][j] != word[path.size()]) {
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
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    CHECK(s.exist(board, "ABCCED") == true);
    CHECK(s.exist(board, "SEE") == true);
    CHECK(s.exist(board, "ABCB") == false);

    board = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };
    CHECK(s.exist(board, "AAB") == true);
}

int main() {
    test();
    return 0;
}
