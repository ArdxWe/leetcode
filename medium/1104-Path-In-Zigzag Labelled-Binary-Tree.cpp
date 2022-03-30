/*
 * In an infinite binary tree where every node has two children, the nodes are
 * labelled in row order. In the odd numbered rows (ie., the first, third,
 * fifth,...), the labelling is left to right, while in the even numbered rows
 * (second, fourth, sixth,...), the labelling is right to left. Given the label
 * of a node in this tree, return the labels in the path from the root of the
 * tree to the node with that label.
 */

#include <cassert>
#include <vector>

namespace {
using std::vector;

inline bool is_one(int value, int left_shift) {
  assert(left_shift >= 0);
  return (value & (1 << left_shift)) != 0;
}

inline int max_one(int value) {
  assert(sizeof(int) == 4);

  for (int i = 4 * 8 - 1; i >= 0; i--) {
    if (is_one(value, i)) {
      return i + 1;
    }
  }
  return -1;
}

int other(int value) {
  int left = 1 << (max_one(value) - 1);
  int right = left * 2 - 1;
  int len = value - left;
  return right - len;
}
}  // namespace

class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    assert(label >= 1);
    int size = max_one(label);
    vector<int> res(size, 0);
    res[size - 1] = label;

    bool reverse = (size % 2 == 0);
    int now_level = reverse ? other(label) / 2 : label / 2;
    reverse = !reverse;
    for (int i = size - 2; i >= 0; i--) {
      if (reverse) {
        res[i] = other(now_level);
        reverse = false;
        now_level = now_level / 2;
      } else {
        reverse = true;
        res[i] = now_level;
        now_level = now_level / 2;
      }
    }
    return res;
  }
};
