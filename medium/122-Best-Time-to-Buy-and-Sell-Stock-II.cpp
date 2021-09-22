/* You are given an integer array prices where prices[i] is the price of a given
 * stock on the ith day. On each day, you may decide to buy and/or sell the
 * stock. You can only hold at most one share of the stock at any time. However,
 * you can buy it then immediately sell it on the same day. Find and return the
 * maximum profit you can achieve.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int dp[2][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
      dp[1][0] =
          dp[0][0] < dp[0][1] + prices[i] ? dp[0][1] + prices[i] : dp[0][0];
      dp[1][1] =
          dp[0][0] - prices[i] < dp[0][1] ? dp[0][1] : dp[0][0] - prices[i];
      dp[0][0] = dp[1][0];
      dp[0][1] = dp[1][1];
    }
    return dp[0][0] > dp[0][1] ? dp[0][0] : dp[0][1];
  }
};

int main() {
  Solution s;
  vector<int> v = {7, 6, 4, 3, 1};
  cout << s.maxProfit(v) << endl;
  return 0;
}
