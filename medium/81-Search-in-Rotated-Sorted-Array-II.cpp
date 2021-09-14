/* There is an integer array nums sorted in non-decreasing order (not
 * necessarily with distinct values).
 * Before being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is [nums[k],
 * nums[k+1],
 * ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example,
 * [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become
 * [4,5,6,6,7,0,1,2,4,4].
 * Given the array nums after the rotation and an integer target, return true if
 * target is in nums, or false if it is not in nums.
 * You must decrease the overall operation steps as much as possible.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int m = 0;
    int n = nums.size() - 1;

    while (m <= n) {
      int mid = (m + n) / 2;
      if (nums[mid] == target) {
        return true;
      }

      if (nums[m] < nums[mid]) {
        if (target >= nums[m] && target < nums[mid]) {
          n = mid - 1;
        } else {
          m = mid + 1;
        }
      } else if (nums[mid] < nums[n]) {
        if (target > nums[mid] && target <= nums[n]) {
          m = mid + 1;
        } else {
          n = mid - 1;
        }
      } else {
        if (nums[m] == target || nums[n] == target) {
          return true;
        }
        m++;
        n--;
      }
    }
    return false;
  }
};

/*
int main() {
  Solution s;
  vector<int> v{2, 5, 6, 0, 0, 1, 2};
  cout << s.search(v, 3) << endl;
  return 0;
}
*/
