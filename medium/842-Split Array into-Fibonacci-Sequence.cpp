/*
 * You are given a string of digits num, such as "123456579". We can split it
 * into a Fibonacci-like sequence [123, 456, 579]. Formally, a Fibonacci-like
 * sequence is a list f of non-negative integers such that: 0 <= f[i] < 231,
 * (that is, each integer fits in a 32-bit signed integer type), f.length >= 3,
 * and f[i]
 * + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2. Note that when
 * splitting the string into pieces, each piece must not have extra leading
 * zeroes, except if the piece is the number 0 itself. Return any Fibonacci-like
 * sequence split from num, or return [] if it cannot be done.
 */

#include <cassert>
#include <string>
#include <utility>
#include <vector>

namespace {
using std::pair;
using std::string;
using std::vector;

// [start, end] -> (flag, res)
pair<bool, int> builder(const string& s, int start, int end) {
  assert(start >= 0 && end >= 0 && end >= start && end < s.size());

  if (end - start + 1 > 10) {
    return {false, 0};
  }

  if (s[start] == '0') {
    if (start == end) {
      return {true, 0};
    }
    return {false, 0};
  }

  int64_t res = 0;
  int times = 0;
  for (int i = end; i >= start; i--) {
    int64_t mul = 1;
    for (int j = 0; j < times; j++) {
      mul = mul * 10;
    }
    res += mul * (s[i] - '0');
    times++;
  }

  int64_t max_32 = 0x7FFFFFFF;
  if (res > max_32) {
    return {false, 0};
  }
  return {true, static_cast<int>(res)};
}
}  // namespace

class Solution {
 public:
  vector<int> splitIntoFibonacci(string num) {
    vector<int> v;
    real(&v, num, 0);
    return res_;
  }

  void real(vector<int>* v, const string& s, int start) {
    if (!res_.empty()) {
      return;
    }

    if (start >= s.size()) {
      if (v->size() > 2) {
        res_ = *v;
      }
      return;
    }
    for (int i = start; i < s.size(); i++) {
      auto t = builder(s, start, i);
      if (!t.first) {
        continue;
      }
      if (v->size() >= 2 &&
          (*v)[v->size() - 1] != t.second - (*v)[v->size() - 2]) {
        continue;
      }
      v->push_back(t.second);
      real(v, s, i + 1);
      v->pop_back();
    }
  }

 private:
  vector<int> res_{};
};
