/*
 * Given an n x n binary matrix grid, return the length of the shortest clear
 * path in the matrix. If there is no clear path, return -1.
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0,
 * 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that: All the
 * visited cells of the path are 0. All the adjacent cells of the path are
 * 8-directionally connected (i.e., they are different and they share an edge or
 * a corner). The length of a clear path is the number of visited cells of this
 * path.
 */

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::int64_t;
using std::pair;
using std::unordered_set;
using std::vector;

int64_t encode(const pair<int, int>& x) {
  return (static_cast<int64_t>(x.first) << 32) + static_cast<int64_t>(x.second);
}

pair<int, int> decode(int64_t x) {
  return pair<int, int>{static_cast<int>(x >> 32),
                        static_cast<int>(x & 0xffffffff)};
}

bool equal(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first == b.first && a.second == b.second;
}

}  // namespace

class Solution {
 public:
  int shortestPathBinaryMatrix(const vector<vector<int>>& grid) {
    if (grid[0][0] != 0 || grid[grid.size() - 1][grid[0].size() - 1] != 0)
      return -1;
    unordered_set<int64_t> sets;
    pair<int, int> now = {0, 0};
    pair<int, int> target = {grid.size() - 1, grid[0].size() - 1};

    sets.insert(encode(now));
    auto computed = sets;

    auto find = [&grid, &computed](int i, int j) -> vector<pair<int, int>> {
      auto valid = [&grid, &computed](int a, int b) -> bool {
        return (a >= 0 && a < grid.size()) && (b >= 0 && b < grid[0].size()) &&
               (grid[a][b] == 0) &&
               computed.find(encode(pair<int, int>{a, b})) == computed.end();
      };
      vector<pair<int, int>> res;
      if (valid(i - 1, j - 1)) res.push_back({i - 1, j - 1});
      if (valid(i - 1, j)) res.push_back({i - 1, j});
      if (valid(i - 1, j + 1)) res.push_back({i - 1, j + 1});
      if (valid(i, j - 1)) res.push_back({i, j - 1});
      if (valid(i, j + 1)) res.push_back({i, j + 1});
      if (valid(i + 1, j - 1)) res.push_back({i + 1, j - 1});
      if (valid(i + 1, j)) res.push_back({i + 1, j});
      if (valid(i + 1, j + 1)) res.push_back({i + 1, j + 1});
      return res;
    };

    for (int i = 0;; i++) {
      unordered_set<int64_t> new_set;
      for (const auto& item : sets) {
        auto p = decode(item);
        if (equal(p, target)) {
          return i + 1;
        } else {
          auto v = find(p.first, p.second);
          for (auto& i : v) {
            if (computed.find(encode(i)) == computed.end()) {
              new_set.insert(encode(i));
              computed.insert(encode(i));
            }
          }
        }
      }

      if (new_set.empty()) {
        return -1;
      }
      sets = new_set;
    }
    assert(false);
  }
};

int main() {
  vector<vector<int>> v;
  v.push_back({0, 0, 1, 0, 1, 1});
  v.push_back({1, 0, 0, 1, 0, 0});
  v.push_back({0, 1, 0, 1, 0, 0});
  v.push_back({1, 0, 1, 0, 0, 0});
  v.push_back({0, 1, 0, 1, 0, 0});
  v.push_back({0, 0, 0, 0, 0, 0});

  Solution s;
  cout << s.shortestPathBinaryMatrix(v) << endl;
  return 0;
}
