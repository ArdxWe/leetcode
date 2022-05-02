/*
 * Let's play the minesweeper game (Wikipedia, online game)!
 * You are given an m x n char matrix board representing the game board where:
 * 'M' represents an unrevealed mine,
 * 'E' represents an unrevealed empty square,
 * 'B' represents a revealed blank square that has no adjacent mines (i.e.,
 * above, below, left, right, and all 4 diagonals), digit ('1' to '8')
 * represents how many mines are adjacent to this revealed square, and 'X'
 * represents a revealed mine. You are also given an integer array click where
 * click = [clickr, clickc] represents the next click position among all the
 * unrevealed squares ('M' or 'E'). Return the board after revealing this
 * position according to the following rules: If a mine 'M' is revealed, then
 * the game is over. You should change it to 'X'. If an empty square 'E' with no
 * adjacent mines is revealed, then change it to a revealed blank 'B' and all of
 * its adjacent unrevealed squares should be revealed recursively. If an empty
 * square 'E' with at least one adjacent mine is revealed, then change it to a
 * digit ('1' to '8') representing the number of adjacent mines. Return the
 * board when no more squares will be revealed.
 */

#include <cassert>
#include <utility>
#include <vector>

using std::move;
using std::pair;
using std::vector;

class Solution {
 private:
  pair<vector<pair<int, int>>, int> neighbor(const pair<int, int>& now, int x,
                                             int y,
                                             vector<vector<char>>& board) {
    pair<vector<pair<int, int>>, int> res{vector<pair<int, int>>{}, 0};

    auto valid = [&x, &y](pair<int, int>& p) -> bool {
      return (p.first >= 0 && p.first < x) && (p.second >= 0 && p.second < y);
    };

    vector<pair<int, int>> temp;
    temp.push_back({now.first - 1, now.second - 1});
    temp.push_back({now.first - 1, now.second});
    temp.push_back({now.first - 1, now.second + 1});
    temp.push_back({now.first, now.second - 1});
    temp.push_back({now.first, now.second + 1});
    temp.push_back({now.first + 1, now.second - 1});
    temp.push_back({now.first + 1, now.second});
    temp.push_back({now.first + 1, now.second + 1});

    for (auto& item : temp) {
      if (valid(item)) {
        if (board[item.first][item.second] == 'M' ||
            board[item.first][item.second] == 'X') {
          res.second++;
        }
        if (board[item.first][item.second] == 'M' ||
            board[item.first][item.second] == 'E') {
          res.first.push_back(pair<int, int>{item.first, item.second});
        }
      }
    }
    return res;
  }

 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    assert(click.size() == 2);

    int x = board.size();
    int y = board[0].size();
    assert(click[0] >= 0 && click[0] < x);
    assert(click[1] >= 0 && click[1] < y);

    switch (board[click[0]][click[1]]) {
      case 'M': {
        board[click[0]][click[1]] = 'X';
        return board;
      }
      case 'E': {
        auto v = neighbor(pair<int, int>{click[0], click[1]}, x, y, board);
        if (v.second == 0) {
          board[click[0]][click[1]] = 'B';
          for (auto item : v.first) {
            vector<int> v;
            v.push_back(item.first);
            v.push_back(item.second);
            updateBoard(board, v);
          }
        } else {
          board[click[0]][click[1]] = '0' + v.second;
        }
        return board;
      }
      default:
        return board;
    }
  }
};
