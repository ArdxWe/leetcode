/*
 * Given an integer array nums, return all the different possible increasing
 * subsequences of the given array with at least two elements. You may return
 * the answer in any order. The given array may contain duplicates, and two
 * equal integers should also be considered a special case of increasing
 * sequence.
 */

#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using std::move;
using std::string;
using std::unordered_set;
using std::vector;

string change(const vector<int>& v) {
  string s;
  for (auto i : v) {
    s += std::to_string(i) + ",";
  }
  return s;
}

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<vector<int>>> v(nums.size(), vector<vector<int>>{});

    for (int i = 0; i < nums.size(); i++) {
      vector<vector<int>> temp;
      for (int j = 0; j < i; j++) {
        if (nums[j] <= nums[i]) {
          for (const auto& item : v[j]) {
            auto t = item;
            t.push_back(nums[i]);
            temp.push_back(move(t));
          }
        }
      }

      v[i] = move(temp);
      v[i].push_back(vector<int>(1, nums[i]));
    }

    vector<vector<int>> res;
    for (auto& item : v) {
      for (auto& t : item) {
        if (t.size() > 1) res.push_back(move(t));
      }
    }

    vector<vector<int>> t;
    unordered_set<string> set;
    for (auto& i : res) {
      string s = change(i);
      if (set.find(s) == set.end()) {
        t.push_back(move(i));
      }
      set.insert(s);
    }

    return t;
  }
};
