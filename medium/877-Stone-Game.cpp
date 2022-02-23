/*
 * Alice and Bob play a game with piles of stones. There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i]. The objective of the game is to end with the most stones.
 * The total number of stones across all the piles is odd, so there are no ties.
 * Alice and Bob take turns, with Alice starting first. Each turn, a player
 * takes the entire pile of stones either from the beginning or from the end of
 * the row. This continues until there are no more piles left, at which point
 * the person with the most stones wins. Assuming Alice and Bob play optimally,
 * return true if Alice wins the game, or false if Bob wins.
 */

#include <string>
#include <unordered_map>
#include <vector>

namespace {
using std::string;
using std::unordered_map;
using std::vector;

string to_string(int a, int b) {
  return std::to_string(a) + '-' + std::to_string(b);
}
}  // namespace

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    auto sum = [&piles]() -> int {
      int res = 0;
      for (auto i : piles) {
        res += i;
      }
      return res;
    };

    int all = sum();
    return scores(piles, 0, static_cast<int>(piles.size())) > all / 2;
  }

 private:
  int scores(const vector<int>& piles, int start, int end) {
    if (start >= end) {
      return 0;
    }
    if (map_.find(to_string(start, end)) != map_.end()) {
      return map_[to_string(start, end)];
    }

    int pick_start = piles[start];

    int start_other = std::max(scores(piles, start + 1, end - 1),
                               scores(piles, start + 2, end));

    int pick_end = piles[end];
    int end_other = std::max(scores(piles, start, end - 2),
                             scores(piles, start + 1, end - 1));

    int res = std::max(pick_start + start_other, pick_end + end_other);

    map_[to_string(start, end)] = res;
    return res;
  }

  unordered_map<string, int> map_{};
};
