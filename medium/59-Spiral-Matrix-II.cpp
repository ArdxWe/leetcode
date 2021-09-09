// Given a positive integer n,
// generate an n x n matrix filled with elements from 1 to n2 in spiral order.

#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  enum class Direction {
    top = 0,
    right,
    down,
    left,
  };
  vector<vector<int>> generateMatrix(int n) {
    assert(n > 0);

    auto d = Direction::right;
    int all = n * n;

    int now = 1;
    int i = 0;
    int j = 0;

    vector<vector<bool>> flags;
    for (int i = 0; i < n; i++) {
      vector<bool> now;
      for (int j = 0; j < n; j++) {
        now.push_back(false);
      }
      flags.push_back(std::move(now));
    }

    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      vector<int> now;
      for (int j = 0; j < n; j++) {
        now.push_back(0);
      }
      res.push_back(std::move(now));
    }
    while (now <= all) {
      res[i][j] = now++;
      flags[i][j] = true;
      switch (d) {
        case Direction::right:
          if (j + 1 < n && flags[i][j + 1] == false) {
            j++;
          } else {
            d = Direction::down;
            i++;
          }
          break;
        case Direction::down:
          if (i + 1 < n && flags[i + 1][j] == false) {
            i++;
          } else {
            d = Direction::left;
            j--;
          }
          break;
        case Direction::left:
          if (j - 1 >= 0 && flags[i][j - 1] == false) {
            j--;
          } else {
            d = Direction::top;
            i--;
          }
          break;
        case Direction::top:
          if (i - 1 >= 0 && flags[i - 1][j] == false) {
            i--;
          } else {
            j++;
            d = Direction::right;
          }
          break;
        default:
          assert(0);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  auto x = s.generateMatrix(10000);
  for (auto& i : x) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}