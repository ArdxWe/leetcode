/* Given two version numbers, version1 and version2, compare them.
 * Version numbers consist of one or more revisions joined by a dot '.'. Each
 * revision consists of digits and may contain leading zeros. Every revision
 * contains at least one character. Revisions are 0-indexed from left to right,
 * with the leftmost revision being revision 0, the next revision being revision
 * 1, and so on. For example 2.5.33 and 0.1 are valid version numbers. To
 * compare version numbers, compare their revisions in left-to-right order.
 * Revisions are compared using their integer value ignoring any leading zeros.
 * This means that revisions 1 and 001 are considered equal. If a version number
 * does not specify a revision at an index, then treat the revision as 0. For
 * example, version 1.0 is less than version 1.1 because their revision 0s are
 * the same, but their revision 1s are 0 and 1 respectively, and 0 < 1. Return
 * the following: If version1 < version2, return -1. If version1 > version2,
 * return 1. Otherwise, return 0.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::stringstream;
using std::vector;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    auto transfer = [](vector<string>& s) -> vector<int> {
      vector<int> res;
      for (auto& x : s) {
        res.push_back(std::stoi(x));
      }
      return res;
    };

    auto split = [](string& s) -> vector<string> {
      int begin = 0;
      vector<string> res;

      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
          res.push_back(string(s.data() + begin, i - begin));
          begin = i + 1;
        } else if (i == s.size() - 1) {
          res.push_back(string(s.data() + begin, i - begin + 1));
          begin = i + 1;
        }
      }

      return res;
    };

    // string array
    auto a = split(version1);
    auto b = split(version2);

    // int array
    auto x = transfer(a);
    auto y = transfer(b);

    // resize to equal
    int a_len = x.size();
    int b_len = y.size();
    if (a_len > b_len) {
      for (int i = 0; i < a_len - b_len; i++) {
        y.push_back(0);
      }
    } else if (a_len < b_len) {
      for (int i = 0; i < b_len - a_len; i++) {
        x.push_back(0);
      }
    }

    // compare
    for (int i = 0; i < x.size(); i++) {
      if (x[i] == y[i]) {
        continue;
      } else if (x[i] > y[i]) {
        return 1;
      } else {
        return -1;
      }
    }
    return 0;
  }
};

int main() {
  string a = {"1.03.23.44444"};
  string b = {"34.34.34.3.3"};
  Solution s;
  cout << s.compareVersion(a, b) << endl;
  return 0;
}
