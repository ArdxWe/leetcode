/* Given the coordinates of two rectilinear rectangles in a 2D plane, return the
 * total area covered by the two rectangles. The first rectangle is defined by
 * its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2). The
 * second rectangle is defined by its bottom-left corner (bx1, by1) and its
 * top-right corner (bx2, by2).
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>

namespace {
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
}  // namespace

class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    pair<int, int> first1 = {ax1, ay1};
    pair<int, int> first2 = {ax2, ay2};

    int first_area = area(first1, first2);

    pair<int, int> second1 = {bx1, by1};
    pair<int, int> second2 = {bx2, by2};

    int second_area = area(second1, second2);

    pair<int, int> first_width = {ax1, ax2};
    pair<int, int> second_width = {bx1, bx2};
    pair<int, int> first_height = {ay1, ay2};
    pair<int, int> second_height = {by1, by2};

    int overlap_areas = overlap(first_width, second_width) *
                        overlap(first_height, second_height);

    return first_area + second_area - overlap_areas;
  }

  int area(pair<int, int> left_down, pair<int, int> right_up) {
    assert(left_down.first <= right_up.first &&
           left_down.second <= right_up.second);

    return (right_up.first - left_down.first) *
           (right_up.second - left_down.second);
  }

  int overlap(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.first && a.first < b.first) {
      return 0;
    }

    if (b.second < a.first && b.first < a.first) {
      return 0;
    }

    if (a.second >= b.first && a.second <= b.second) {
      return a.second - max(a.first, b.first);
    }

    if (a.first >= b.first && a.first <= b.second) {
      return min(b.second, a.second) - a.first;
    }

    return b.second - b.first;
  }
};

int main() {
  Solution s;
  cout << s.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
}
