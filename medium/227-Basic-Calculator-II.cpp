
/* Given a string s which represents an expression, evaluate this expression and
 * return its value.
 * The integer division should truncate toward zero.
 * You may assume that the given expression is always valid. All intermediate
 * results will be in the range of [-231, 231 - 1].
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::string;
using std::vector;

inline bool is_number(const char a) { return a >= '0' && a <= '9'; }

inline bool is_cal(const char a) {
  return a == '+' || a == '-' || a == '*' || a == '/';
}

inline bool is_mul_div(const char s) { return s == '*' || s == '/'; }
}  // namespace

class Solution {
 public:
  int calculate(const string& s) {
    vector<int> nums;
    vector<char> cals;

    string num_s;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;  // ignore ' '

      if (is_number(s[i])) {
        num_s.push_back(s[i]);
      } else {
        assert(is_cal(s[i]));

        int num = 0;
        if (!num_s.empty()) {
          num = atoi(num_s.c_str());
          nums.push_back(num);
          num_s = string{};
        }

        if (is_mul_div(s[i])) {
          int other;
          char temp = s[i];

          bool flag = false;
          for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == ' ') continue;

            if (is_number(s[j])) {
              num_s.push_back(s[j]);
            } else {
              flag = true;
              other = atoi(num_s.c_str());

              num_s = string{};
              i = j - 1;
              break;
            }
          }

          if (!flag) {
            other = atoi(num_s.c_str());
            num_s = string{};
            i = s.size();
          }

          int first = nums[nums.size() - 1];
          nums.pop_back();

          if (temp == '*') {
            nums.push_back(first * other);
          } else {
            nums.push_back(first / other);
          }
        } else {
          cals.push_back(s[i]);
        }
      }
    }

    if (!num_s.empty()) {
      int t;
      t = atoi(num_s.c_str());
      nums.push_back(t);
    }

    int res = nums[0];

    int pos = 0;
    for (auto cal : cals) {
      if (cal == '+') {
        res += nums[pos + 1];
      } else {
        res -= nums[pos + 1];
      }
      pos++;
    }

    return res;
  }
};

int main() {
  Solution s;

  string t = "323423424 ";
  cout << s.calculate(t) << endl;
}
