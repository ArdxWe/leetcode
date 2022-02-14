/*
 * Given an array of strings words and an integer k, return the k most frequent
 * strings. Return the answer sorted by the frequency from highest to lowest.
 * Sort the words with the same frequency by their lexicographical order.
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;
}  // namespace

class Solution {
 public:
  vector<string> topKFrequent(const vector<string>& words, int k) {
    unordered_map<string, int> map;

    for (const auto& word : words) {
      if (map.find(word) == map.end()) {
        map[word] = 1;
      } else {
        map[word]++;
      }
    }

    struct Value {
      int counts;
      string s;

      Value(int counts, const string& ss) : counts(counts), s(ss) {}
    };

    vector<Value> v;
    for (const auto& pair : map) {
      v.emplace_back(pair.second, pair.first);
    }

    auto compare = [](const Value& a, const Value& b) -> bool {
      if (a.counts > b.counts) {
        return true;
      }
      if (a.counts == b.counts) {
        return a.s < b.s;
      }
      return false;
    };

    sort(v.begin(), v.end(), compare);

    vector<string> res;
    res.reserve(k);

    for (int i = 0; i < k; i++) {
      res.emplace_back(move(v[i].s));
    }
    return res;
  }
};
