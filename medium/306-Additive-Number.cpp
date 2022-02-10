/*
 * An additive number is a string whose digits can form an additive sequence.
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the sum
 * of the preceding two. Given a string containing only digits, return true if
 * it is an additive number or false otherwise. Note: Numbers in the additive
 * sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is
 * invalid.
 */

#include <cassert>
#include <iostream>
#include <string>

namespace {
using std::cout;
using std::endl;
using std::string;

inline int char_to_int(char c) {
  assert(c >= '0' && c <= '9');
  return c - '0';
}

inline char int_to_char(int i) {
  assert(i >= 0 && i <= 9);
  return static_cast<char>(i + '0');
}

inline bool legal(const string& s) { return !(s.size() > 1 && s[0] == '0'); }

string adder(const string& a, const string& b) {
  string res;

  // the last index
  int a_cur = static_cast<int>(a.size()) - 1;
  int b_cur = static_cast<int>(b.size()) - 1;

  int up = 0;
  while (a_cur >= 0 && b_cur >= 0) {
    int now = char_to_int(a[a_cur]) + char_to_int(b[b_cur]) + up;

    up = now / 10;
    now = now % 10;
    res = std::to_string(now) + res;

    a_cur--;
    b_cur--;
  }

  if (a_cur < 0 && b_cur < 0) {
    if (up == 0) {
      return res;
    }
    return int_to_char(up) + res;
  }

  if (a_cur < 0) {
    if (up == 0) {
      return string(b.data(), b_cur + 1) + res;
    }
    return adder(string(b.data(), b_cur + 1), std::to_string(up)) + res;
  }

  assert(b_cur < 0);
  if (up == 0) {
    return string(a.data(), a_cur + 1) + res;
  }
  return adder(string(a.data(), a_cur + 1), std::to_string(up)) + res;
}
}  // namespace

class Solution {
 public:
  bool isAdditiveNumber(string num) {
    if (num.empty()) {
      return true;
    }
    for (int i = 0; i < static_cast<int>(num.size()); i++) {
      string first = string(num.data(), i + 1);

      // pass
      if (!legal(first)) {
        continue;
      }

      for (int j = i + 1; j < static_cast<int>(num.size()); j++) {
        string second = string(num.data() + i + 1, j - i);

        // pass
        if (!legal(second)) {
          continue;
        }

        string res = adder(first, second);

        if (num.size() - j >= res.size() &&
            res == string(num.data() + j + 1, res.size())) {
          if (ok(second, res,
                 string(num.data() + first.size() + second.size() +
                        res.size()))) {
            return true;
          }
        }
      }
    }
    return false;
  }

 private:
  bool ok(const string& prev_prev, const string& prev, const string& now) {
    if (now.empty()) return true;
    string res = adder(prev_prev, prev);

    if (now.size() >= res.size() && string(now.data(), res.size()) == res) {
      return ok(prev, res, string(now.data() + res.size()));
    }
    return false;
  }
};

int main() {
  Solution s;

  cout << s.isAdditiveNumber("199001200") << endl;
  return 0;
}
