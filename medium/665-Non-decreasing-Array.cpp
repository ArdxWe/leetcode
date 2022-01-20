/*
 * Given an array nums with n integers, your task is to check if it could become
 * non-decreasing by modifying at most one element. We define an array is
 * non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such
 * that (0 <= i <= n - 2).
 */

#include <utility>
#include <vector>

using std::pair;
using std::vector;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    if (nums.size() < 2) {
      return true;
    }

    pair<int, int> low;

    bool flag = false;
    for (int i = 1; i < static_cast<int>(nums.size()); i++) {
      if (nums[i - 1] > nums[i]) {
        if (flag) {
          return false;
        }
        low.first = i - 1;
        low.second = i;
        flag = true;
      }
    }

    if (!flag) {
      return true;
    }

    if (low.first == 0 || low.second == nums.size() - 1) {
      return true;
    }

    return nums[low.first - 1] <= nums[low.second] ||
           nums[low.first] <= nums[low.second + 1];
  }
};
