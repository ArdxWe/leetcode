/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below). The robot can only move either down or right at any point
 * in time. The robot is trying to reach the bottom-right corner of the grid
 * (marked 'Finish' in the diagram below). Now consider if some obstacles are
 * added to the grids. How many unique paths would there be? An obstacle and
 * space is marked as 1 and 0 respectively in the grid.
 */

#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int x = obstacleGrid.size();
    int y = obstacleGrid[0].size();
    assert(x > 0);
    assert(y > 0);
    if (obstacleGrid[0][0] == 1 || obstacleGrid[x - 1][y - 1] == 1) return 0;
    vector<vector<int>> copy = obstacleGrid;

    for (auto& x : copy) {
      for (auto& y : x) {
        y = 0;
      }
    }
    copy[0][0] = 1;

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (i == 0 && j == 0) continue;
        if (obstacleGrid[i][j] == 1) {
          copy[i][j] = 0;
          continue;
        }
        if (j - 1 >= 0) {
          copy[i][j] = copy[i][j - 1];
        }
        if (i - 1 >= 0) {
          copy[i][j] += copy[i - 1][j];
        }
      }
    }
    return copy[x - 1][y - 1];
  }
};

/*
int main() {
  vector<vector<int>> x;
  x.push_back({0, 1});
  x.push_back({0, 0});

  Solution s;
  cout << s.uniquePathsWithObstacles(x) << endl;
  return 0;
}
*/
