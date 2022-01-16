/*
 * You are given an integer num. You can swap two digits at most once to get the
 * maximum valued number. Return the maximum valued number you can get.
 */

#include <vector>

namespace {
using std::max;
using std::vector;
}  // namespace

class Solution {
 public:
  int maximumSwap(int num) {
    int value = num;

    vector<int> v;
    while (value != 0) {
      v.push_back(value % 10);
      value = value / 10;
    }

    for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) {
      int max_value = 0;
      int max_index = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (v[j] > v[i] && v[j] >= max_value) {
          max_value = v[j];
          max_index = j;
        }
      }

      {
        if (v[max_index] > v[i]) {
          int temp = v[max_index];
          v[max_index] = v[i];

          v[i] = temp;

          int res = 0;
          for (int t = v.size() - 1; t >= 0; t--) {
            res = res * 10 + v[t];
          }

          return res;
        }
      }
    }

    return num;
  }
};
