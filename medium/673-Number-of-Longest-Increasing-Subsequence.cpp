/*
 * Given an integer array nums, return the number of longest increasing
 * subsequences. Notice that the sequence has to be strictly increasing.
 */

#include <utility>
#include <vector>

namespace {
using std::max;
using std::pair;
using std::vector;
}  // namespace

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> len_counts(nums.size(),
                                      {0 /* len */, 0 /* counts */});

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
      // get max len
      int max_len = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          max_len = max(len_counts[j].first, max_len);
        }
      }

      len_counts[i].first = max_len + 1;

      // get counts
      int counts = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] &&
            len_counts[j].first == len_counts[i].first - 1) {
          counts += len_counts[j].second;
        }
      }

      if (counts == 0)
        len_counts[i].second = 1;
      else
        len_counts[i].second = counts;
    }

    int max_len = 0;
    for (auto& i : len_counts) {
      max_len = max(max_len, i.first);
    }

    int res = 0;
    for (auto& i : len_counts) {
      if (i.first == max_len) {
        res += i.second;
      }
    }
    return res;
  }
};
