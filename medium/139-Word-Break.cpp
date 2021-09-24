/* Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary words.
 * Note that the same word in the dictionary may be reused multiple times in the
 * segmentation.
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    for (auto& s : wordDict) {
      set_.insert(s);
    }

    return dfs(s, 0);
  }

  bool dfs(string& s, int start) {
    if (start >= s.size()) {
      return true;
    }
    if (cache_.find(start) != cache_.end()) {
      return cache_[start];
    }

    bool res = false;
    for (int i = start; i < s.size(); i++) {
      if (set_.find(string(s.data() + start, i - start + 1)) != set_.end()) {
        res = res || dfs(s, i + 1);
        if (res) {
          cache_[start] = true;
          return true;
        }
      }
    }
    cache_[start] = false;
    return false;
  }

 private:
  unordered_set<string> set_{};
  unordered_map<int, bool> cache_{};
};
