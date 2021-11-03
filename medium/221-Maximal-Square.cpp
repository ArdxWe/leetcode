/* Given an m x n binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 */

#include <algorithm>
#include <vector>

namespace {
using std::max;
using std::min;
using std::vector;
}  // namespace

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    vector<vector<bool>> flags;

    vector<bool> v;
    for (const auto& i : matrix) {
      for (auto j : i) {
        v.push_back(false);
      }
      flags.push_back(v);
      v.clear();
    }

    auto left_up_counts = [&matrix](int i, int j, int start_res = 0) -> int {
      int res = start_res;

      while (true) {
        for (int x = i; x <= i + res; x++) {
          if (matrix[x][j + res] == '0') {
            return res;
          }
        }

        for (int y = j; y < j + res; y++) {
          if (matrix[i + res][y] == '0') {
            return res;
          }
        }
        res++;
        if (res == matrix.size() - i || res == matrix[0].size() - j) {
          return res;
        }
      }
    };

    int res = 0;

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (flags[i][j]) {
          continue;
        }

        int counts = left_up_counts(i, j);
        res = max(res, counts);

        for (int k = 0; k < counts; k++) {
          for (int l = 0; l < counts; l++) {
            flags[i + k][j + l] = true;
            if (k == 0 && l == 0) {
              break;
            }
            counts = left_up_counts(i + k, j + l,
                                    min(counts - k - 1, counts - l - 1));
            res = max(res, counts);
          }
        }
      }
    }
    return res * res;
  }
};
