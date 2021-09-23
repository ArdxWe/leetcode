/* Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'. A region is captured by flipping all
 * 'O's into 'X's in that surrounded region.
 */

#include <vector>

using std::vector;

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
      vector<bool> now;
      for (int j = 0; j < board[i].size(); j++) {
        now.push_back(false);
      }
      flags_.push_back(std::move(now));
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (i == 0 || i == board.size() - 1 || j == 0 ||
            j == board[i].size() - 1) {
          if (board[i][j] == 'O') {
            dfs(i, j, board);
          }
        }
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (!flags_[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(int i, int j, vector<vector<char>>& board) {
    flags_[i][j] = true;

    if (i + 1 < board.size() && board[i + 1][j] == 'O' && !flags_[i + 1][j]) {
      dfs(i + 1, j, board);
    }
    if (i - 1 >= 0 && board[i - 1][j] == 'O' && !flags_[i - 1][j]) {
      dfs(i - 1, j, board);
    }
    if (j + 1 < board[i].size() && board[i][j + 1] == 'O' &&
        !flags_[i][j + 1]) {
      dfs(i, j + 1, board);
    }
    if (j - 1 >= 0 && board[i].size() && board[i][j - 1] == 'O' &&
        !flags_[i][j - 1]) {
      dfs(i, j - 1, board);
    }
  }

 private:
  vector<vector<bool>> flags_{};
};