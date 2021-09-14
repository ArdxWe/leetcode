/* Given an integer array nums sorted in non-decreasing order, remove some
 * duplicates in-place such that each unique element appears at most twice. The
 * relative order of the elements should be kept the same. Since it is
 * impossible to change the length of the array in some languages, you must
 * instead have the result be placed in the first part of the array nums. More
 * formally, if there are k elements after removing the duplicates, then the
 * first k elements of nums should hold the final result. It does not matter
 * what you leave beyond the first k elements. Return k after placing the final
 * result in the first k slots of nums. Do not allocate extra space for another
 * array. You must do this by modifying the input array in-place with O(1) extra
 * memory.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }
    int slow = 2;
    for (int i = 2; i < nums.size(); i++) {
      if (nums[slow - 1] == nums[slow - 2] && nums[i] == nums[slow - 1]) {
        continue;
      } else {
        nums[slow++] = nums[i];
      }
    }
    return slow;
  }
};

/*
int main() {
    Solution s;
    vector<int> v{0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << s.removeDuplicates(v) << endl;
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
*/
