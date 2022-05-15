/*
 * We can use run-length encoding (i.e., RLE) to encode a sequence of integers.
 * In a run-length encoded array of even length encoding (0-indexed), for all
 * even i, encoding[i] tells us the number of times that the non-negative
 * integer value encoding[i + 1] is repeated in the sequence. For example, the
 * sequence arr = [8,8,8,5,5] can be encoded to be encoding = [3,8,2,5].
 * encoding = [3,8,0,9,2,5] and encoding = [2,8,1,8,2,5] are also valid RLE of
 * arr. Given a run-length encoded array, design an iterator that iterates
 * through it. Implement the RLEIterator class: RLEIterator(int[] encoded)
 * Initializes the object with the encoded array encoded. int next(int n)
 * Exhausts the next n elements and returns the last element exhausted in this
 * way. If there is no element left to exhaust, return -1 instead.
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

class RLEIterator {
 public:
  RLEIterator(vector<int>& encoding) { v_ = encoding; }

  int next(int n) {
    while (now_index_ < v_.size()) {
      if (v_[now_index_] > n) {
        v_[now_index_] -= n;
        return v_[now_index_ + 1];
      } else if (v_[now_index_] == n) {
        now_index_ += 2;
        return v_[now_index_ - 1];
      }

      n -= v_[now_index_];
      now_index_ += 2;
    }
    return -1;
  }

 private:
  vector<int> v_{};
  int now_index_ = 0;
};
