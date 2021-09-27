/* Given an integer array nums, find a contiguous non-empty subarray within the
 * array that has the largest product, and return the product. It is guaranteed
 * that the answer will fit in a 32-bit integer. A subarray is a contiguous
 * subsequence of the array.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    vector<pair<int, int>> arr{nums.size(), {0, 0}};
    arr[0] = {nums[0], nums[0]};
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      arr[i] = {std::max(std::max(nums[i], nums[i] * arr[i - 1].first),
                         nums[i] * arr[i - 1].second),
                std::min(std::min(nums[i], nums[i] * arr[i - 1].first),
                         nums[i] * arr[i - 1].second)};
      res = std::max(res, arr[i].first);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 3, -2, 4};
  cout << s.maxProduct(v) << endl;
}
