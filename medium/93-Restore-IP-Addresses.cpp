/* Given a string s containing only digits, return all possible valid IP
 * addresses that can be obtained from s. You can return them in any order.
 * A valid IP address consists of exactly four integers, each integer is between
 * 0 and 255, separated by single dots and cannot have leading zeros. For
 * example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
 */

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
  vector<string> restoreIpAddresses(string s) {
    vector<int> now{};
    vector<string> res{};

    dfs(res, now, s, 0);
    return res;
  }

  void dfs(vector<string>& res, vector<int>& now, string& s, int index) {
    int len = s.size();

    if (index > len - 1) {
      if (now.size() == 4) {
        stringstream stream;
        for (int i = 0; i < 3; i++) {
          stream << now[i] << '.';
        }
        stream << now[3];
        res.push_back(stream.str());
      }
      return;
    }

    if (now.size() >= 4) {
      return;
    }

    now.push_back(s[index] - '0');
    dfs(res, now, s, index + 1);
    now.pop_back();

    auto get = [](string& s, int index, int size) {
      int a = 0;
      int b = 0;
      int c = 0;

      a = s[index] - '0';
      if (a == 0) {
        return -1;
      }
      b = s[index + 1] - '0';
      if (size == 3) {
        c = s[index + 2] - '0';
        return a * 100 + b * 10 + c;
      } else {
        return a * 10 + b;
      }
    };

    if (index + 1 > len - 1) {
      return;
    }
    int temp;

    temp = get(s, index, 2);
    if (temp >= 10 && temp <= 99) {
      now.push_back(temp);
      dfs(res, now, s, index + 2);
      now.pop_back();
    }

    if (index + 2 > len - 1) {
      return;
    }

    temp = get(s, index, 3);
    if (temp >= 0 && temp <= 255) {
      now.push_back(temp);
      dfs(res, now, s, index + 3);
      now.pop_back();
    }
  }
};
/*
int main() {
  Solution s;
  auto v = s.restoreIpAddresses(string{"101023"});

  for (auto& x : v) {
    cout << x << endl;
  }
  return 0;
}
*/
