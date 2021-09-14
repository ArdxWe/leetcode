/* Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid. The word can be constructed from letters of
 * sequentially adjacent cells, where adjacent cells are horizontally or
 * vertically neighboring. The same letter cell may not be used more than once.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::move;
using std::string;
using std::vector;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    assert(!board.empty());

    int m = board.size();
    int n = board[0].size();

    assert(n > 0);

    for (int i = 0; i < m; i++) {
      vector<bool> now(n, false);
      flags_.push_back(move(now));
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
    if (board[i][j] != word[index]) {
      return false;
    }

    if (index == word.size() - 1) {
      return true;
    }

    flags_[i][j] = true;

    if (i - 1 >= 0 && (!flags_[i - 1][j])) {
      if (dfs(board, i - 1, j, word, index + 1)) {
        return true;
      }
    }

    if (i + 1 < board.size() && (!flags_[i + 1][j])) {
      if (dfs(board, i + 1, j, word, index + 1)) {
        return true;
      }
    }
    if (j - 1 >= 0 && (!flags_[i][j - 1])) {
      if (dfs(board, i, j - 1, word, index + 1)) {
        return true;
      }
    }
    if (j + 1 < board[0].size() && (!flags_[i][j + 1])) {
      if (dfs(board, i, j + 1, word, index + 1)) {
        return true;
      }
    }

    flags_[i][j] = false;
    return false;
  }

 private:
  vector<vector<bool>> flags_{};
};

/*
int main() {
  Solution s;
  vector<vector<char>> board;
  board.push_back(vector<char>{'A', 'B', 'C', 'E'});
  board.push_back(vector<char>{'S', 'C', 'D', 'S'});
  board.push_back(vector<char>{'A', 'B', 'E', 'E'});

  string word = "ABCB";

  cout << s.exist(board, word) << endl;
  return 0;
}
*/
