/* You are given an array prices where prices[i] is the price of a given stock
 * on the ith day, and an integer fee representing a transaction fee. Find the
 * maximum profit you can achieve. You may complete as many transactions as you
 * like, but you need to pay the transaction fee for each transaction. Note: You
 * may not engage in multiple transactions simultaneously (i.e., you must sell
 * the stock before you buy again).
 */

#include <utility>
#include <vector>

namespace {
using std::max;
using std::pair;
using std::vector;
}  // namespace

class Solution {
 public:
  int maxProfit(const vector<int>& prices, int fee) {
    vector<pair<int, int>> v(prices.size(), {0, 0});

    v[0].first = 0;
    v[0].second = -prices[0];

    for (int i = 1; i < static_cast<int>(v.size()); i++) {
      v[i].first = max(v[i - 1].first, v[i - 1].second - fee + prices[i]);
      v[i].second = max(v[i].first - prices[i], v[i - 1].second);
    }

    return v[v.size() - 1].first;
  }
};
