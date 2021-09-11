/* Given an integer array nums of unique elements, return all possible subsets
 * (the power set). The solution set must not contain duplicate subsets. Return
 * the solution in any order.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    dfs(0, nums.size() - 1, nums);
    return res_;
  }

  void dfs(int cur, int size, vector<int>& nums) {
    if (cur > size) {
      res_.push_back(temp_);
      return;
    }

    temp_.push_back(nums[cur]);
    dfs(cur + 1, size, nums);
    temp_.pop_back();
    dfs(cur + 1, size, nums);
  }

 private:
  vector<vector<int>> res_{};
  vector<int> temp_{};
};

/*
int main() {
  Solution s;
  vector<int> t = {1, 2, 4, 5};
  auto v = s.subsets(t);
  for (auto& x : v) {
    for (auto r : x) {
      cout << r << " ";
    }
    cout << endl;
  }
  return 0;
}
*/
