/* Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::vector;
}  // namespace

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, pair<bool, int>> map;

    int x = nums.size() / 3;
    vector<int> res;

    for (int i : nums) {
      if (map.find(i) == map.end()) {
        map[i] = {false, 1};
      } else {
        map[i].second = map[i].second + 1;
      }

      if (!map[i].first && map[i].second > x) {
        res.push_back(i);
        map[i].first = true;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 1, 1, 3, 3, 2, 2, 2};
  auto _ = s.majorityElement(v);
  for (auto t : _) {
    cout << t << " ";
  }
  cout << endl;
  return 0;
}
