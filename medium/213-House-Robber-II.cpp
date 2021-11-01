/* You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night. Given an integer array nums representing the amount of money
 * of each house, return the maximum amount of money you can rob tonight without
 * alerting the police.
 */

#include <string>
#include <unordered_map>
#include <vector>

namespace {
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;
}  // namespace

class Solution {
 public:
  int rob(const vector<int>& nums) {
    int res = std::max(func(nums, 2, nums.size() - 2) + nums[0],
                       func(nums, 1, nums.size() - 1));
    map_.clear();
    return res;
  }

  int func(const vector<int>& nums, int start, int end) {
    if (start > end) return 0;

    string s = to_string(start) + " " + to_string(end);
    if (map_.find(s) != map_.end()) {
      return map_[s];
    }
    int a = func(nums, start + 2, end);
    int b = func(nums, start + 1, end);
    int c = std::max(a + nums[start], b);

    map_[s] = c;  // cache
    return std::max(func(nums, start + 2, end) + nums[start],
                    func(nums, start + 1, end));
  }

 private:
  unordered_map<string, int> map_{};
};
