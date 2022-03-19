/*
 * A magical string s consists of only '1' and '2' and obeys the following
 * rules: The string s is magical because concatenating the number of contiguous
 * occurrences of characters '1' and '2' generates the string s itself. The
 * first few elements of s is s = "1221121221221121122……". If we group the
 * consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22
 * ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2
 * 2 1 2 2 ......". You can see that the occurrence sequence is s itself.
 * Given an integer n, return the number of 1's in the first n number in the
 * magical string s.
 */

#include <cstdint>
#include <iostream>
#include <vector>

namespace {
using std::cout;
using std::endl;
using std::uint64_t;
using std::vector;
}  // namespace

class Solution {
 public:
  Solution() {
    first_.reserve(default_size_);
    second_.reserve(default_size_);

    first_.push_back(true);
    first_.push_back(false);
    first_.push_back(false);

    second_.push_back(true);
    second_.push_back(false);

    while (cached_.size() < default_size_) {
      resize();
    }
  }

  int magicalString(int n) {
    while (cached_.size() < n) {
      resize();
    }

    return cached_[n - 1];
  }

 private:
  void resize() {
    // add second then add first
    int size = first_.size() - second_.size();

    int old_size = second_.size();

    bool last_one = first_[first_.size() - 1];
    for (int i = old_size; i < old_size + size; i++) {
      second_.push_back(first_[i]);
      if (last_one) {
        if (first_[i]) {
          first_.push_back(false);
        } else {
          first_.push_back(false);
          first_.push_back(false);
        }
        last_one = false;
      } else {
        if (first_[i]) {
          first_.push_back(true);
        } else {
          first_.push_back(true);
          first_.push_back(true);
        }
        last_one = true;
      }
    }

    // make cache follow first
    old_size = cached_.size();
    int last = 0;
    if (!cached_.empty()) {
      last = cached_[cached_.size() - 1];
    }

    for (int i = old_size; i < first_.size(); i++) {
      if (first_[i]) {
        cached_.push_back(last + 1);
        last++;
      } else {
        cached_.push_back(last);
      }
    }
  }

 private:
  // vector<bool> every item is 1 bit ?
  vector<bool> first_{};
  vector<bool> second_{};

  const uint64_t default_size_ = 0x1000;

  vector<int> cached_{};
};

int main() {
  Solution s;
  cout << s.magicalString(10000000) << endl;
  return 0;
}
