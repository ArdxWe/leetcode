// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
 public:
  enum class Direction {
    top = 0,
    right,
    down,
    left,
  };

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return vector<int>{};
    }
    if (matrix.size() == 1) {
      return matrix[0];
    }

    vector<vector<bool>> x;
    for (int i = 0; i < matrix.size(); i++) {
      vector<bool> now;
      for (int j = 0; j < matrix[0].size(); j++) {
        now.push_back(false);
      }
      x.push_back(std::move(now));
    }
    auto d = Direction::right;
    int all = matrix.size() * matrix[0].size();

    int now = 0;
    int i = 0;
    int j = 0;
    vector<int> res;
    while (now < all) {
      res.push_back(matrix[i][j]);
      now++;
      x[i][j] = true;
      switch (d) {
        case Direction::right:
          if (j + 1 < matrix[0].size() && x[i][j + 1] == false) {
            j++;
          } else {
            d = Direction::down;
            i++;
          }
          break;
        case Direction::down:
          if (i + 1 < matrix.size() && x[i + 1][j] == false) {
            i++;
          } else {
            d = Direction::left;
            j--;
          }
          break;
        case Direction::left:
          if (j - 1 >= 0 && x[i][j - 1] == false) {
            j--;
          } else {
            d = Direction::top;
            i--;
          }
          break;
        case Direction::top:
          if (i - 1 >= 0 && x[i - 1][j] == false) {
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

/*
int main() {
  Solution s;
  vector<vector<int>> x;
  x.push_back(vector<int>{1, 2, 3, 4});
  x.push_back(vector<int>{5, 6, 7, 8});
  x.push_back(vector<int>{9, 10, 11, 12});

  vector<int> res = s.spiralOrder(x);

  for (const auto i : res) {
    cout << i << "  ";
  }
  cout << endl;
} */
