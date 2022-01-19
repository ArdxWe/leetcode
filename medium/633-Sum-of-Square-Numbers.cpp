/* Given a non-negative integer c, decide whether there're two integers a and b
 * such that a2 + b2 = c.
 */

#include <cmath>

class Solution {
 public:
  bool judgeSquareSum(int c) {
    long long end = static_cast<int>(sqrt(static_cast<double>(c)));
    long long start = 0;

    while (start <= end) {
      long long res = start * start + end * end;
      if (res == c) {
        return true;
      }
      if (res > c) {
        end--;
      } else {
        start++;
      }
    }
    return false;
  }
};
