/*
 * Design a map that allows you to do the following:
 * Maps a string key to a given value.
 * Returns the sum of the values that have a key with a prefix equal to a given
 * string. Implement the MapSum class: MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one. int sum(string prefix) Returns the sum of all the pairs' value
 * whose key starts with the prefix.
 */

#include <array>
#include <memory>
#include <string>
#include <unordered_map>

namespace {
using std::array;
using std::pair;
using std::string;
using std::unique_ptr;
using std::unordered_map;

const int kSize = 26;

struct Node {
  array<pair<unique_ptr<Node>, int>, kSize> nodes{};
  int value = 0;
};

inline int char_index(char c) { return c - 'a'; }
}  // namespace

class MapSum {
 public:
  MapSum() {}

  int sum(string prefix) {
    Node* cur = &node_;

    int sum = 0;
    for (char c : prefix) {
      if (!cur->nodes[char_index(c)].first) {
        return 0;
      }

      sum = cur->nodes[char_index(c)].second;

      cur = cur->nodes[char_index(c)].first.get();
    }

    return sum;
  }

  void insert(string key, int val) {
    if (maps_.find(key) == maps_.end()) {
      real_insert(key, val);
    } else {
      int old = maps_[key];
      real_insert(key, val - old);
    }

    maps_[key] = val;
  }

 private:
  void real_insert(string key, int val) {
    Node* cur = &node_;

    for (char c : key) {
      if (!cur->nodes[char_index(c)].first) {
        cur->nodes[char_index(c)] = pair{unique_ptr<Node>(new Node()), val};
      } else {
        cur->nodes[char_index(c)].second += val;
      }

      cur = cur->nodes[char_index(c)].first.get();
    }
  }
  Node node_{};
  unordered_map<string, int> maps_{};
};
