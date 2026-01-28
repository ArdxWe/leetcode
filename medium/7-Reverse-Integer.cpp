#include <cstdint>
#include <vector>

namespace {
using std::vector;
}

class Solution {
 public:
  int reverse(int x) {
    if (x == 0 || x == INT32_MIN) {
      return 0;
    }

    vector<int> v;
    bool positive = x > 0 ? true : false;
    if (!positive) {
      x = -x;
    }

    while (x != 0) {
      v.push_back(x % 10);
      x /= 10;
    }

    int reverse = 0;

    for (int i = 0; i < v.size(); i++) {
      if ((INT32_MAX - v[i]) / 10 < reverse) {
        return 0;
      }

      reverse = reverse * 10 + v[i];
    }

    return positive ? reverse : -reverse;
  }
};
