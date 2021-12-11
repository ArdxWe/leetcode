/* Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order. You must write an
 * algorithm that runs in linear runtime complexity and uses only constant extra
 * space.
 *
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int all_xor = 0;
    for (auto t : nums) {
      all_xor = all_xor ^ t;
    }

    // two number not equal bit
    int mask = 0;

    // - int min will overflow
    if (all_xor == 0x80000000) {
      mask = all_xor;
    } else {
      mask = all_xor & (-all_xor);
    }

    vector<int> res(2, 0);
    for (auto t : nums) {
      if ((t & mask) == 0) {
        res[0] = res[0] ^ t;
      } else {
        res[1] = res[1] ^ t;
      }
    }

    return res;
  }
};
