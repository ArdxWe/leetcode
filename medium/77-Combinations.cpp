/* Given two integers n and k, return all possible combinations of k numbers out
 * of the range [1, n]. You may return the answer in any order.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    dfs(1, n, k);
    return res_;
  }

  void dfs(int cur, int n, int k) {
    if (cur == n + 1) {
      if (tmp_.size() == k) {
        res_.push_back(tmp_);
      }
      return;
    }

    tmp_.push_back(cur);
    dfs(cur + 1, n, k);
    tmp_.pop_back();
    dfs(cur + 1, n, k);
  }

 private:
  vector<int> tmp_{};
  vector<vector<int>> res_{};
};

/*
int main() {
  Solution s;
  auto v = s.combine(4, 2);
  for (auto& x : v) {
    for (auto r : x) {
      cout << r << " ";
    }
    cout << endl;
  }
  return 0;
}
*/
