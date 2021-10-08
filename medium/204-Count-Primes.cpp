/* Given an integer n, return the number of prime numbers that are strictly less
 * than n. */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int countPrimes(int n) {
    vector<int> v(n + 1, 1);

    int res = 0;
    for (int i = 2; i < n; i++) {
      if (v[i] == 1) {
        res++;
        for (long long j =
                 static_cast<long long>(i) * static_cast<long long>(i);
             j < n; j += i) {
          v[j] = 0;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.countPrimes(100000000) << endl;
  return 0;
}
