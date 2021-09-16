/* An n-bit gray code sequence is a sequence of 2n integers where:
 * Every integer is in the inclusive range [0, 2n - 1],
 * The first integer is 0, An integer appears no more than once in the sequence,
 * The binary representation of every pair of adjacent integers differs by
 * exactly one bit, and The binary representation of the first and last integers
 * differs by exactly one bit. Given an integer n, return any valid n-bit gray
 * code sequence.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n == 0) {
      vector<int> temp;
      temp.push_back(0);
      return temp;
    } else if (n == 1) {
      vector<int> temp;
      temp.push_back(0);
      temp.push_back(1);
      return temp;
    }

    vector<int> res;
    res.push_back(0);
    res.push_back(1);
    res.reserve(1 << n);
    for (int i = 1; i < n; i++) {
      int prev_size = res.size();
      for (int j = prev_size - 1; j >= 0; j--) {
        res.push_back(res[j] + (1 << i));
      }
    }
    return res;
  }
};

/*
int main() {
  Solution s;
  auto v = s.grayCode(2);
  for (auto& value : v) {
    cout << value << endl;
  }
  cout << endl;
  return 0;
}
*/
