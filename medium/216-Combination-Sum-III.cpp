/* Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true: Only numbers 1 through 9 are used. Each number
 * is used at most once. Return a list of all possible valid combinations. The
 * list must not contain the same combination twice, and the combinations may be
 * returned in any order.
 */

#include <iostream>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::vector;
}  // namespace

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    if (k * (k + 1) / 2 > n) {  // no
      return vector<vector<int>>{};
    } else if (k * (k + 1) / 2 == n) {  // all
      vector<int> v;
      for (int i = 1; i <= k; i++) {
        v.push_back(i);
      }
      vector<vector<int>> res;
      res.push_back(v);
      return res;
    } else {
      vector<int> _;
      dfs(1, k, n, _, 0);
      return res_;
    }
  }

  void dfs(int start, int k, int n, vector<int>& v, int sum) {
    if (start > 9) {  // should end
      return;
    }

    if (v.size() + 1 == k) {   // should add last item
      if (n - sum >= start) {  // could add
        if (n - sum <= 9) {    // should less than 10
          v.push_back(n - sum);
          res_.push_back(v);
          v.pop_back();
        }
      }
    } else {
      for (int i = start; i < (n > 9 ? 10 : n); i++) {
        v.push_back(i);
        sum += i;
        dfs(i + 1, k, n, v, sum);
        sum -= i;
        v.pop_back();
      }
    }
  }

 private:
  vector<vector<int>> res_{};
};

int main() {
  Solution s;
  auto v = s.combinationSum3(9, 45);
  for (auto i : v) {
    cout << " ";
    for (auto t : i) {
      cout << t << " ";
    }
    cout << endl;
  }
  return 0;
}
