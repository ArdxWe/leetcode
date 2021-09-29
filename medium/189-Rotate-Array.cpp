/* Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k = k % len;

    int now;
    int temp;
    int count = 0;
    for (int i = 0; i < k; i++) {
      now = nums[i];
      for (int x = (i + k) % len; x != i; x = (x + k) % len) {
        temp = now;
        now = nums[x];
        nums[x] = temp;
        count++;
      }
      nums[i] = now;
      count++;
      if (count == len) {
        return;
      }
    }
  }
};

int main() {
  vector<int> x = {-1, -100, 3, 99};
  Solution s;
  s.rotate(x, 2);
  for (auto i : x) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}