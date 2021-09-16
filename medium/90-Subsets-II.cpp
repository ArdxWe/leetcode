/* Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set). The solution set must not contain duplicate subsets.
 * Return the solution in any order.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<bool> flags(nums.size(), false);
    vector<int> now;
    dfs(nums, 0, flags, now);
    res_.push_back(vector<int>{});
    return res_;
  }

  void dfs(vector<int>& v, int index, vector<bool>& flags, vector<int>& now) {
    if (index >= v.size()) {
      return;
    }

    if (index > 0 && v[index] == v[index - 1] && flags[index - 1] == false) {
      dfs(v, index + 1, flags, now);
    } else {
      flags[index] = true;
      now.push_back(v[index]);
      res_.push_back(now);
      dfs(v, index + 1, flags, now);
      flags[index] = false;
      now.pop_back();
      dfs(v, index + 1, flags, now);
    }
  }

 private:
  vector<vector<int>> res_{};
};

/*
int main() {
  Solution s;
  vector<int> v = {4, 4, 4, 1, 4};
  auto x = s.subsetsWithDup(v);
  for (auto t : x) {
    for (auto i : t) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
