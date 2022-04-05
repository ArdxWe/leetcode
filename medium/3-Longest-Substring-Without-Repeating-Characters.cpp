/* Given a string s, find the length of the longest substring without repeating
 * characters.
 */

#include <string>
#include <unordered_map>

namespace {
using std::string;
using std::unordered_map;
}  // namespace

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int start = 0;
    int end = 0;
    unordered_map<char, int> map;
    int res = 0;
    while (end < static_cast<int>(s.size())) {
      int now = end - start;

      while (true) {
        if (end < static_cast<int>(s.size())) {
          if (map.find(s[end]) == map.end()) {
            now++;
            map[s[end]] = end;
            end++;
          } else {
            res = std::max(res, now);
            int temp = map[s[end]] + 1;
            for (int i = start; i < map[s[end]] + 1; i++) {
              map.erase(s[i]);
            }
            start = temp;

            map[s[end]] = end;
            end++;
            break;
          }
        } else {
          res = std::max(res, now);
          break;
        }
      }
    }
    return res;
  }
};
