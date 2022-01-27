/* Given an array of unique integers, arr, where each integer arr[i] is strictly
 * greater than 1.
 * We make a binary tree using these integers, and each number may be used for
 * any number of times. Each non-leaf node's value should be equal to the
 * product of the values of its children. Return the number of binary trees we
 * can make. The answer may be too large so return the answer modulo 109 + 7.
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

using std::sort;
using std::unordered_map;
using std::vector;

namespace {
const int kMod = 1000000000 + 7;
}

class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    vector<int64_t> dp(arr.size(), 1);

    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++) {
      map[arr[i]] = i;
    }

    int64_t res = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (arr[i] % arr[j] == 0 && map.find(arr[i] / arr[j]) != map.end()) {
          int right = map[arr[i] / arr[j]];
          dp[i] += (dp[j] * dp[right]) % kMod;
        }
      }
      res = (res + dp[i]) % kMod;
    }

    return static_cast<int>(res);
  }
};
