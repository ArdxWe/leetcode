/* A peak element is an element that is strictly greater than its neighbors.
 * Given an integer array nums, find a peak element, and return its index. If
 * the array contains multiple peaks, return the index to any of the peaks. You
 * may imagine that nums[-1] = nums[n] = -∞. You must write an algorithm that
 * runs in O(log n) time.
 */

#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    assert(!nums.empty());

    int n = nums.size();
    int res = nums.size() / 2;

    auto get = [&](int index) -> std::pair<int, int> {
      if (index < 0 || index >= n) {
        return {0, 0};
      } else {
        return {0, nums[index]};
      }
    };

    while (!(get(res - 1) < get(res) && get(res) < get(res + 1))) {
      if (get(res - 1) < get(res)) {
        res++;
      } else {
        res--;
      }
    }
    return res;
  }
};
