/*
 * Given an integer array nums with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array. Implement the Solution class: Solution(int[] nums)
 * Initializes the object with the array nums. int pick(int target) Picks a
 * random index i from nums where nums[i] == target. If there are multiple valid
 * i's, then each index should have an equal probability of returning.
 */

#include <random>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {
using std::default_random_engine;
using std::move;
using std::random_device;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

// [start, end]
int random(int start, int end) {
  random_device r;

  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(start, end);

  return uniform_dist(e1);
}

}  // namespace

class Solution {
 public:
  Solution(vector<int>& nums) {
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
      if (map_.find(nums[i]) == map_.end()) {
        vector<int> x(1, i);
        map_[nums[i]] = move(x);
      } else {
        map_[nums[i]].push_back(i);
      }
    }
  }

  int pick(int target) {
    return map_[target][random(0, map_[target].size() - 1)];
  }

 private:
  unordered_map<int, vector<int>> map_{};
};
