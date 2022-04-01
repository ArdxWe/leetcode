/* You are given an integer array nums and an integer target.
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the integers.
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1". Return the number of
 * different expressions that you can build, which evaluates to target.
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    f(nums, 0, target, 0);
    return res_;
  }

 private:
  void f(vector<int>& nums, int now, int target, int res) {
    if (now >= nums.size()) {
      if (res == target) {
        res_++;
      }
      return;
    }
    f(nums, now + 1, target, res + nums[now]);
    f(nums, now + 1, target, res - nums[now]);
  }

  int res_ = 0;
};
