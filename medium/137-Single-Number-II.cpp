/* Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> map;
    for (auto i : nums) {
      if (map.find(i) == map.end()) {
        map[i] = 1;
      } else {
        map[i]++;
      }
    }

    for (auto& pair : map) {
      if (pair.second == 1) {
        return pair.first;
      }
    }
    return -1;
  }
};
