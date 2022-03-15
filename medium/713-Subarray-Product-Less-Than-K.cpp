/*
 * Given an array of integers nums and an integer k, return the number of
 * contiguous sub arrays where the product of all the elements in the subarray
 * is strictly less than k.
 */

#include <cstdint>
#include <iostream>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::vector;
}  // namespace

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res = 0;
    int left = 0;

    uint64_t mul = 1;
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
      // mul right
      mul = mul * nums[i];

      // add left to make mul < k
      for (; left <= i; left++) {
        if (mul >= k) {
          mul = mul / nums[left];
        } else {
          // end left count
          res += i - left + 1;
          break;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v{10, 5, 2, 6};
  cout << s.numSubarrayProductLessThanK(v, 100) << endl;
  return 0;
}
