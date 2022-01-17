/*
 * You are given an integer n. We reorder the digits in any order (including the
 * original order) such that the leading digit is not zero. Return true if and
 * only if we can do this so that the resulting number is a power of two.
 */

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace {
using std::sort;
using std::string;
using std::to_string;
using std::unordered_set;
using std::vector;

string change(int val) {
  string s = to_string(val);

  vector<char> v;
  for (auto c : s) {
    v.push_back(c);
  }

  sort(v.begin(), v.end());
  return string{v.data(), v.size()};
}
}  // namespace

class Solution {
 public:
  Solution() {
    int val = 1;
    for (int i = 0; i < sizeof(int) * 8; i++) {
      sorted_.insert(change(val << i));
    }
  }

  bool reorderedPowerOf2(int n) {
    string s = change(n);

    return sorted_.find(s) != sorted_.end();
  }

 private:
  unordered_set<string> sorted_{};
};
