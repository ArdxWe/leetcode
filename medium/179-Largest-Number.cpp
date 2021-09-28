/* Given a list of non-negative integers nums, arrange them such that they form
 * the largest number. Note: The result may be very large, so you need to return
 * a string instead of an integer.
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> x;
    for (auto i : nums) {
      x.push_back(std::to_string(i));
    }
    std::sort(x.begin(), x.end(), [](string& a, string& b) {
      int len = std::min(a.size(), b.size());
      for (int i = 0; i < len; i++) {
        if (a[i] > b[i]) {
          return false;
        } else if (a[i] < b[i]) {
          return true;
        } else {
          continue;
        }
      }

      if (a.size() > len) {
        return string(a.data() + len, a.size() - len) + b < a;
      } else {
        return string(b.data() + len, b.size() - len) + a > b;
      }
    });
    stringstream stream;
    for (auto i = x.end() - 1; i >= x.begin(); i--) {
      stream << *i;
    }
    auto res = stream.str();
    if (res[0] == '0') {
      return "0";
    } else {
      return res;
    }
  }
};

int main() {
  Solution s;
  vector<int> x = {123, 333, 45, 6};
  cout << s.largestNumber(x) << endl;
  return 0;
}
