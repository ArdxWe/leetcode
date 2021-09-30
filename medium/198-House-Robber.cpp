/* You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night. Given an integer array nums representing
 * the amount of money of each house, return the maximum amount of money you can
 * rob tonight without alerting the police.
 */

#include <vector>

using std::vector;

class Solution {
 public:
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);

    dp[0] = nums[0];
    for (int i = 1; i < dp.size(); i++) {
      if (i == 1) {
        dp[i] = std::max(nums[0], nums[1]);
      } else {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
      }
    }
    return dp[dp.size() - 1];
  }
};
