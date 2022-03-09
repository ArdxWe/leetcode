/*
 * Given two strings s1 and s2, return the lowest ASCII sum of deleted
 * characters to make two strings equal.
 */

#include <string>
#include <vector>

namespace {
using std::string;
using std::vector;
}  // namespace

class Solution {
 public:
  int minimumDeleteSum(const string& s1, const string& s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    auto get = [](const string& s, int index) -> int {
      return static_cast<int>(static_cast<unsigned char>(s[index]));
    };

    for (int j = static_cast<int>(s2.size() - 1); j >= 0; j--) {
      dp[s1.size()][j] = get(s2, j) + dp[s1.size()][j + 1];
    }
    for (int i = static_cast<int>(s1.size() - 1); i >= 0; i--) {
      dp[i][s2.size()] = get(s1, i) + dp[i + 1][s2.size()];
    }

    for (int i = static_cast<int>(s1.size() - 1); i >= 0; i--) {
      for (int j = static_cast<int>(s2.size() - 1); j >= 0; j--) {
        if (s1[i] == s2[j]) {
          dp[i][j] = dp[i + 1][j + 1];
        } else {
          dp[i][j] =
              std::min(dp[i][j + 1] + get(s2, j), dp[i + 1][j] + get(s1, i));
        }
      }
    }
    return dp[0][0];
  }
};
