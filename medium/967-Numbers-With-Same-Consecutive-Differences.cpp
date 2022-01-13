/*
 * Return all non-negative integers of length n such that the absolute
 * difference between every two consecutive digits is k. Note that every number
 * in the answer must not have leading zeros. For example, 01 has one leading
 * zero and is invalid. You may return the answer in any order.
 */

#include <cassert>
#include <string>
#include <vector>

namespace {
using std::string;
using std::vector;
}  // namespace

class Solution {
 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    string s;
    vector<int> res;
    compute(s, 0, n, k, &res);

    return res;
  }

 private:
  void compute(string& s, int now, int n, int k, vector<int>* output) {
    if (now == n) {
      output->push_back(atoi(s.data()));
      return;
    }

    assert(s.size() == now);

    if (now == 0) {
      for (int i = 0; i < 10; i++) {
        if (i == 0) {
          continue;
        }

        if (i + k < 10 || i - k >= 0) {
          s.push_back('0' + i);
          compute(s, now + 1, n, k, output);
          s.pop_back();
        }
      }

    } else {
      if ((s[now - 1] - '0') + k <= 9) {
        s.push_back(s[now - 1] + k);
        compute(s, now + 1, n, k, output);
        s.pop_back();
      }

      if (k != 0 /* if k == 0, we get same result */ &&
          s[now - 1] - '0' - k >= 0) {
        s.push_back(s[now - 1] - k);
        compute(s, now + 1, n, k, output);
        s.pop_back();
      }
    }
  }
};
