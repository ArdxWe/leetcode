/*
 * Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
 */

#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 1) {
      return 1;
    }
    if (n == 0) {
      return 1.0;
    }
    if (n == 1) {
      return x;
    }
    if (n == -1) {
      return 1 / x;
    }
    bool negative = n < 0;
    if (negative) {
      if (n == 0x80000000) {
        return myPow(x, n + 1) * myPow(x, -1);
      }
      n = -n;
    }
    if (map_.find(n) != map_.end()) {
      return map_[n];
    }

    double left;
    double right;
    if (n % 2 == 0) {
      left = myPow(x, n >> 1);
      map_[n] = left * left;
      return negative ? 1 / map_[n] : map_[n];
    } else {
      left = myPow(x, n >> 1);
      right = myPow(x, n - (n >> 1));
      map_[n] = left * right;
      return negative ? 1 / map_[n] : map_[n];
    }
  }

 private:
  unordered_map<int, double> map_{};
};

/*
int main() {
  Solution x;
  cout << x.myPow(1.00000, -2147483648) << endl;
  return 0;
} */
