/* A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * To decode an encoded message, all the digits must be grouped then mapped back
 * into letters using the reverse of the mapping above (there may be multiple
 * ways). For example, "11106" can be mapped into: "AAJF" with the grouping (1 1
 * 10 6) "KJF" with the grouping (11 10 6) Note that the grouping (1 11 06) is
 * invalid because "06" cannot be mapped into 'F' since "6" is different from
 * "06". Given a string s containing only digits, return the number of ways to
 * decode it. The answer is guaranteed to fit in a 32-bit integer.
 */

#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
 public:
  int numDecodings(string s) { return dfs(s, 0); }

  int dfs(string& s, int index) {
    if (cache_.find(index) != cache_.end()) {
      return cache_[index];
    }
    int res = 0;
    if (index > s.size() - 1) {
      return 1;
    }

    if (s[index] >= '1' && s[index] <= '9') {
      res += dfs(s, index + 1);
    }

    if (index + 1 < s.size() &&
            ((s[index] == '1' && s[index + 1] >= '0' && s[index + 1] <= '9')) ||
        (s[index] == '2' && s[index + 1] >= '0' && s[index + 1] <= '6')) {
      res += dfs(s, index + 2);
    }
    cache_[index] = res;
    return res;
  }

 private:
  unordered_map<int, int> cache_{};
};

/*
int main() {
  Solution s;
  cout << s.numDecodings("111111111111111111111111111111111111111111111")
       << endl;
}
*/
