/* You are given an n x n 2D matrix representing an image,
 * rotate the image by 90 degrees (clockwise).
 * You have to rotate the image in-place,
 * which means you have to modify the input 2D matrix directly.
 * DO NOT allocate another 2D matrix and do the rotation.
*/

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::endl;
using std::cout;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    assert(matrix.size() == matrix[0].size());

    vector<vector<int>> new_m = matrix;

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        new_m[j][matrix.size() - 1 - i] = matrix[i][j];
      }
    }
    matrix = new_m;
  }
};

/* int main()
{
  Solution x;
  vector<vector<int>> t;
  t.push_back(vector<int>{1, 2, 3, 4});
  t.push_back(vector<int>{5, 6, 7, 8});
  t.push_back(vector<int>{9, 10, 11, 12});
  t.push_back(vector<int>{13, 14, 15, 16});

  x.rotate(t);
  for (auto& i : t) {
    for (auto& j : i) {
      cout << j << " ";
    }
     cout << endl;
  }
  return 0;
} */