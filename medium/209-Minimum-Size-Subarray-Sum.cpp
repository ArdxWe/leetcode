/* Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
 * numsr-1, numsr] of which the sum is greater than or equal to target. If there
 * is no such subarray, return 0 instead.
 */

#include <algorithm>
#include <iostream>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::min;
using std::vector;
}  // namespace

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0;  // stat pointer
    int end = 0;    // end pointer
    int sum = 0;    // now sums
    int res = nums.size();

    while (end < nums.size()) {
      sum += nums[end];
      if (sum >= target) {
        while (sum - nums[start] >= target) {
          sum -= nums[start];
          start++;
        }
        res = min(res, end - start + 1);
      }

      end++;
    }
    return sum >= target ? res : 0;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, 1, 2, 4, 3};
  cout << s.minSubArrayLen(7, v) << endl;
  return 0;
}
