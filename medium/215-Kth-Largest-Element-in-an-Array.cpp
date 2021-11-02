/* Given an integer array nums and an integer k, return the kth largest element
 * in the array. Note that it is the kth largest element in the sorted order,
 * not the kth distinct element.
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::max;
using std::vector;
}  // namespace

class Heap {
 public:
  Heap(const vector<int>& nums) : v_{nums} { create(); }

  int k_max(int k) {
    assert(k <= v_.size());

    if (k < counts_) {
      return v_[v_.size() - k];
    }

    int counts = k - counts_;
    for (int i = 0; i < counts; i++) {
      get_one_max();
    }
    return v_[v_.size() - k];
  }

 private:
  void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void create() {
    for (int i = (v_.size() - 2) / 2; i >= 0; i--) {
      down(i, v_.size());
    }
  }

  void down(int now, int end) {
    while (true) {
      if (now * 2 + 1 >= end) {
        break;
      }

      if (now * 2 + 2 < end) {
        if (max(v_[now * 2 + 1], v_[now * 2 + 2]) <= v_[now]) {
          break;
        } else {
          if (v_[now * 2 + 1] > v_[now * 2 + 2]) {
            swap(&v_[now], &v_[now * 2 + 1]);
            now = now * 2 + 1;
            continue;
          } else {
            swap(&v_[now], &v_[now * 2 + 2]);
            now = now * 2 + 2;
            continue;
          }
        }
      } else {
        if (v_[now * 2 + 1] > v_[now]) {
          swap(&v_[now], &v_[now * 2 + 1]);
        }

        now = now * 2 + 1;
      }
    }
  }

  void get_one_max() {
    int now_size = v_.size() - counts_;

    swap(&v_[0], &v_[now_size - 1]);

    counts_++;
    build();
  }

  void build() {
    int now_size = v_.size() - counts_;
    down(0, now_size);
  }

  vector<int> v_;
  int counts_ = 0;
};

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) { return Heap{nums}.k_max(k); }
};

int main() {
  Solution s;
  vector<int> v = {2, 1};
  int a = s.findKthLargest(v, 2);
  cout << a << endl;
  return 0;
}
