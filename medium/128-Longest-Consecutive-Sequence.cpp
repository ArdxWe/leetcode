/* Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence. You must write an algorithm that runs in O(n)
 * time. Example 1: Input: nums = [100,4,200,1,3,2] Output: 4 Explanation: The
 * longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length
 * is 4. Example 2: Input: nums = [0,3,7,2,5,8,4,6,0,1] Output: 9
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, pair<int, int>> map;
    int res = 0;
    for (auto i : nums) {
      if (map.find(i) != map.end()) {
        continue;
      }

      if (map.find(i - 1) == map.end()) {
        map[i].first = 1;
      } else {
        map[i].first = map[i - 1].first + 1;
      }

      if (map.find(i + 1) == map.end()) {
        map[i].second = 1;
      } else {
        map[i].second = map[i + 1].second + 1;
      }
      if (map.find(i - 1) != map.end()) {
        map[i - map[i].first + 1].second += map[i].second;
      }
      if (map.find(i + 1) != map.end()) {
        map[i + map[i].second - 1].first += map[i].first;
      }
    }

    for (auto p : map) {
      res = res > p.second.first + p.second.second - 1
                ? res
                : p.second.first + p.second.second - 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {100, 4, 200, 1, 3, 2};
  cout << s.longestConsecutive(v) << endl;
  return 0;
}
