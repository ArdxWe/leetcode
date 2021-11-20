/* Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i]. The product
 * of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You
 * must write an algorithm that runs in O(n) time and without using the division
 * operation.
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> l(nums.size(), 1);
    vector<int> r(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
      l[i] = l[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
      r[i] = r[i + 1] * nums[i + 1];
    }

    vector<int> res(nums.size(), 0);
    for (int i = 0; i < res.size(); i++) {
      res[i] = l[i] * r[i];
    }
    return res;
  }
};
