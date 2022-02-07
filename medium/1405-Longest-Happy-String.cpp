/*
 * A string s is called happy if it satisfies the following conditions:
 * s only contains the letters 'a', 'b', and 'c'.
 * s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * s contains at most a occurrences of the letter 'a'.
 * s contains at most b occurrences of the letter 'b'.
 * s contains at most c occurrences of the letter 'c'.
 * Given three integers a, b, and c, return the longest possible happy string.
 * If there are multiple longest happy strings, return any of them. If there is
 * no such string, return the empty string "". A substring is a contiguous
 * sequence of characters within a string.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::max;
using std::string;

int max(int a, int b, int c) {
  if (a > b) {
    return max(a, c);
  }
  return max(b, c);
}

}  // namespace

class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    string res;

    int prev_prev = -1;
    int prev = -1;

    while (a != 0 || b != 0 || c != 0) {
      int max_v = max(a, b, c);
      assert(max_v != 0);

      if (max_v == a) {
        if (prev == 0 && prev_prev == 0) {
          int x = max(b, c);
          if (x == 0) {
            break;
          } else {
            if (x == b) {
              res += 'b';
              b--;
              prev_prev = prev;
              prev = 1;
            } else {
              res += 'c';
              c--;
              prev_prev = prev;
              prev = 2;
            }
          }
        } else {
          res += 'a';
          a--;
          prev_prev = prev;
          prev = 0;
        }
      } else if (max_v == b) {
        if (prev == 1 && prev_prev == 1) {
          int x = max(a, c);
          if (x == 0) {
            break;
          } else {
            if (x == a) {
              res += 'a';
              a--;
              prev_prev = prev;
              prev = 0;
            } else {
              res += 'c';
              c--;
              prev_prev = prev;
              prev = 2;
            }
          }
        } else {
          res += 'b';
          b--;
          prev_prev = prev;
          prev = 1;
        }
      } else {
        if (prev == 2 && prev_prev == 2) {
          int x = max(a, b);
          if (x == 0) {
            break;
          } else {
            if (x == a) {
              res += 'a';
              a--;
              prev_prev = prev;
              prev = 0;
            } else {
              res += 'b';
              b--;
              prev_prev = prev;
              prev = 1;
            }
          }
        } else {
          res += 'c';
          c--;
          prev_prev = prev;
          prev = 2;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution s;

  cout << s.longestDiverseString(4, 42, 7) << endl
       << s.longestDiverseString(4, 42, 7).size() << endl;
  return 0;
}
