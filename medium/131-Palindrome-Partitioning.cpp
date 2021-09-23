/* Given a string s, partition s such that every substring of the partition is a
 * palindrome. Return all possible palindrome partitioning of s. A palindrome
 * string is a string that reads the same backward as forward.
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<string> now;
    dfs(s, 0, now);
    return res_;
  }

  void dfs(string& s, int start, vector<string>& now) {
    if (start > s.size() - 1) {
      res_.push_back(now);
      return;
    }

    for (int i = start; i < s.size(); i++) {
      if (right(s, start, i)) {
        now.push_back(string{s.data() + start,
                             static_cast<string::size_type>(i - start + 1)});
        dfs(s, i + 1, now);
        now.pop_back();
      }
    }
  }

  bool right(string& s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

 private:
  vector<vector<string>> res_{};
};

int main() {
  string str = "a";
  Solution s;
  auto v = s.partition(str);

  for (auto& i : v) {
    for (auto& t : i) {
      cout << t << " ";
    }
    cout << endl;
  }
  return 0;
}
