/* Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 */

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    if (left == right) {
      return left;
    }
    auto getbit = [](int num, int index) -> bool {
      return (num & (1 << index)) != 0;
    };

    int start = 31;
    for (int i = 31; i >= 0; i--) {
      if (getbit(left, i) != getbit(right, i)) {
        start = i;
        break;
      }
    }
    int res = left & right;
    for (int i = start; i >= 0; i--) {
      res = res & (~(1 << i));
    }
    return res;
  }
};
