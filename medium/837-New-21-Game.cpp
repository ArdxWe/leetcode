/*
 * Alice plays the following game, loosely based on the card game "21".
 * Alice starts with 0 points and draws numbers while she has less than k
 * points. During each draw, she gains an integer number of points randomly from
 * the range [1, maxPts], where maxPts is an integer. Each draw is independent
 * and the outcomes have equal probabilities. Alice stops drawing numbers when
 * she gets k or more points. Return the probability that Alice has n or fewer
 * points. Answers within 10-5 of the actual answer are considered accepted.
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    // no action
    if (k == 0) {
      return 1;
    }

    // value is probability
    vector<double> v(k + maxPts, 0);
    v[0] = 1;

    double res = 0;

    double last_sum = 1;
    bool end_flag = false;

    int start, end;

    for (int i = 1; i < static_cast<int>(v.size()); i++) {
      start = i - maxPts > 0 ? i - maxPts : 0;
      end = std::min(i - 1, k - 1);

      // remove start of last
      if (start > 0) {
        last_sum -= v[start - 1];
      }

      // add new item
      if (end != start && !end_flag) {
        last_sum += v[end];
      }

      // next we don't need add v[end]
      if (end == k - 1) {
        end_flag = true;
      }

      v[i] = last_sum / maxPts;

      if (i >= k && i <= n) {
        res += v[i];
      }
    }
    return res;
  }
};
