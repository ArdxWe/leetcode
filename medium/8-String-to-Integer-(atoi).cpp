#include <iostream>
#include <string>

namespace {
using std::string;
}

class Solution {
 public:
  static int myAtoi(string s) {
    int res = 0;

    bool positive = true;
    bool read_number = false;
    bool read_positive = false;
    bool read_empty = false;

    for (const char c : s) {
      if (c == ' ') {
        if (read_empty && (read_number || read_positive)) {
          return positive ? res : -res;
          ;
        }
        read_empty = true;
        continue;
      }

      if (c == '-' && (!read_number) && (!read_positive)) {
        positive = false;
        read_positive = true;
        continue;
      }

      if (c == '+' && (!read_number) && (!read_positive)) {
        read_positive = true;
        continue;
      }

      if (c >= '0' && c <= '9') {
        read_number = true;

        if ((INT32_MAX - (c - '0')) / 10 < res) {
          return positive ? INT32_MAX : INT32_MIN;
          ;
        }
        res = res * 10 + (c - '0');
      } else {
        break;
      }
    }
    return positive ? res : -res;
  }
};
