/* Given an integer array nums and two integers k and t, return true if there
 * are two distinct indices i and j in the array such that abs(nums[i] -
 * nums[j]) <= t and abs(i - j) <= k.
 */

#include <algorithm>
#include <climits>
#include <set>
#include <vector>

namespace {
using std::max;
using std::min;
using std::set;
using std::vector;
}  // namespace

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    set<int> rec;
    for (int i = 0; i < n; i++) {
      auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
      if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
        return true;
      }
      rec.insert(nums[i]);
      if (i >= k) {
        rec.erase(nums[i - k]);
      }
    }
    return false;
  }
};
