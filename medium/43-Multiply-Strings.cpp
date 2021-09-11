/* Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 */

#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using std::accumulate;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::to_string;
using std::vector;

class Solution {
 public:
  void fix(map<int, vector<int>>& m) {
    int begin = 0;
    int sum = 0;
    for (auto& x : m) {
      begin = x.first;
      sum = accumulate(x.second.begin(), x.second.end(), 0);
      if (sum > 9) {
        x.second.clear();
        x.second.push_back(sum % 10);
        sum = sum / 10;
        begin++;

        while (sum > 0) {
          if (m.find(begin) != m.end()) {
            m[begin].push_back(sum % 10);
          } else {
            m[begin].clear();
            m[begin].push_back(sum % 10);
          }

          sum = sum / 10;
          begin++;
        }
      } else {
        x.second.clear();
        x.second.push_back(sum);
      }
    }
  }

  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return string{"0"};

    map<int, vector<int>> res;  // weight->value

    int result, key;
    for (int i = static_cast<int>(num1.size() - 1); i >= 0; i--) {
      for (int j = static_cast<int>(num2.size() - 1); j >= 0; j--) {
        assert(num1[i] >= '0' && num1[i] <= '9');
        assert(num2[j] >= '0' && num2[j] <= '9');

        result = (num1[i] - '0') * (num2[j] - '0');
        key = static_cast<int>(num1.size()) - 1 - i +
              static_cast<int>(num2.size()) - 1 - j;

        if (result > 9) {
          res[key + 1].push_back(result / 10);
        }
        res[key].push_back(result % 10);
      }
    }
    fix(res);

    string r;
    for (auto t = res.rbegin(); t != res.rend(); t++) {
      r.append(to_string(t->second[0]), 0);
    }
    return r;
  }
};

/*
int main() {
  Solution s;
  cout << s.multiply(string{"23108814760092"}, string{"55183904456427981"});
  return 0;
}
*/
