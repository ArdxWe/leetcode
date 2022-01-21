/*
 * A sequence x1, x2, ..., xn is Fibonacci-like if:
 * n >= 3
 * xi + xi+1 == xi+2 for all i + 2 <= n
 * Given a strictly increasing array arr of positive integers forming a
 * sequence, return the length of the longest Fibonacci-like subsequence of arr.
 * If one does not exist, return 0. A subsequence is derived from another
 * sequence arr by deleting any number of elements (including none) from arr,
 * without changing the order of the remaining elements. For example, [3, 5, 8]
 * is a subsequence of [3, 4, 5, 6, 7, 8].
 */

#include <unordered_set>
#include <vector>

using std::max;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    unordered_set<int> set;
    for (auto i : arr) {
      set.insert(i);
    }
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        int prev = arr[i];
        int next = arr[j];

        int length = 2;
        while (set.find(prev + next) != set.end()) {
          int temp = prev + next;
          prev = next;
          next = temp;
          length++;
        }
        res = max(res, length);
      }
    }
    return res >= 3 ? res : 0;
  }
};
