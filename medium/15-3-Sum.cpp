#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int last_index = static_cast<int>(nums.size()) - 1;
      for (int j = i + 1; j < nums.size(); j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        while (nums[i] + nums[j] + nums[last_index] > 0 && last_index > j) {
          last_index--;
        }

        if (last_index > j && nums[j] + nums[last_index] + nums[i] == 0) {
          ans.push_back({nums[i], nums[j], nums[last_index]});
          continue;
        }

        if (last_index <= j) {
          break;
        }
      }
    }

    return ans;
  }
};
