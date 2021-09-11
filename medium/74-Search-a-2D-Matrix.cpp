/* Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties: Integers in each row are sorted
 * from left to right. The first integer of each row is greater than the last
 * integer of the previous row.
 */

#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    assert(!matrix.empty() && !matrix[0].empty());

    int m = matrix.size();
    int n = matrix[0].size();

    int start = 0;
    int end = m - 1;
    int mid;
    while (start <= end) {
      mid = (start + end) / 2;
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    int col = mid;
    if (mid != 0 && matrix[mid][0] > target) {
      col = mid - 1;
    }
    if (matrix[col][0] > target || matrix[col][n - 1] < target) {
      return false;
    }

    start = 0;
    end = n;
    while (start <= end) {
      mid = (start + end) / 2;
      if (matrix[col][mid] == target) {
        return true;
      } else if (matrix[col][mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return false;
  }
};

/*
int main() {
  Solution s;
  vector<vector<int>> x;
  x.push_back({1, 3, 5, 7});
  x.push_back({2, 3});
  x.push_back({8, 11, 16, 20});
  x.push_back({23, 30, 34, 60});

  cout << s.searchMatrix(x, 3) << endl;
  return 0;
} */
