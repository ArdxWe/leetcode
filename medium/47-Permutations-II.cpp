/* Given a collection of numbers, nums, that might contain duplicates,
 * return all possible unique permutations in any order.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
 private:
  int size_ = 0;

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    size_ = static_cast<int>(nums.size());

    unordered_map<int, int> map;
    for (const auto i : nums) {
      map[i]++;
    }

    vector<int> emp{};
    f(emp, 0, res, map);
    return res;
  }

  void f(vector<int>& now, int index, vector<vector<int>>& res,
         unordered_map<int, int>& map) {
    if (now.size() == size_) {
      res.push_back(now);
    } else {
      for (auto& t : map) {
        if (t.second > 0) {
          now.push_back(t.first);
          t.second--;
          f(now, index + 1, res, map);
          t.second++;
          now.pop_back();
        }
      }
    }
  }
};

/* int main()
{
  Solution x;
  vector<int> t{1, 1, 2, 3, 3, 3};
  auto v = x.permuteUnique(t);
  for (auto& c : v) {
    for (auto f : c) {
      cout << f << " ";
    }
    cout << endl;
  }

  return 0;
} */
