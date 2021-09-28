/* Given an integer n, return the number of trailing zeroes in n!.
 * Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
 */

class Solution {
 public:
  int trailingZeroes(int n) {
    int res = 0;
    while (n > 0) {
      n = n / 5;
      res += n;
    }
    return res;
  }
};
