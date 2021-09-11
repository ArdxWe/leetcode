/* Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue. We will use the integers 0, 1, and 2 to
 * represent the color red, white, and blue, respectively. You must solve this
 * problem without using the library's sort function.
 */

#include <array>
#include <iostream>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    array<int, 3> x = {0};
    for (int i = 0; i < nums.size(); i++) {
      x[nums[i]]++;
    }

    int now;
    for (auto& i : nums) {
      if (x[0] != 0) {
        now = 0;
        x[0]--;
      } else if (x[1] != 0) {
        now = 1;
        x[1]--;
      } else {
        now = 2;
        x[2]--;
      }
      i = now;
    }
  }
};

/*
int main() {
  Solution s;
  vector<int> v = {2, 0, 2, 1, 1, 0};
  s.sortColors(v);

  for (auto t : v) {
    cout << t << " ";
  }
  cout << endl;
}
*/
