/* Design a data structure that follows the constraints of a Least Recently Used
 * (LRU) cache. Implement the LRUCache class: LRUCache(int capacity) Initialize
 * the LRU cache with positive size capacity. int get(int key) Return the value
 * of the key if the key exists, otherwise return -1. void put(int key, int
 * value) Update the value of the key if the key exists. Otherwise, add the
 * key-value pair to the cache. If the number of keys exceeds the capacity from
 * this operation, evict the least recently used key. The functions get and put
 * must each run in O(1) average time complexity.
 */

#include <list>
#include <unordered_map>

using std::list;
using std::pair;
using std::unordered_map;

class LRUCache {
 public:
  LRUCache(int capacity) : cap_{capacity} {}

  int get(int key) {
    if (map_.find(key) == map_.end()) {
      return -1;
    }

    int val = map_[key]->second;
    list_.erase(map_[key]);
    list_.push_front(pair<int, int>{key, val});
    map_[key] = list_.begin();
    return val;
  }

  void put(int key, int value) {
    if (map_.find(key) == map_.end()) {
      if (map_.size() == cap_) {
        auto end = prev(list_.end());
        map_.erase(end->first);
        list_.erase(end);
      }
      list_.push_front(pair<int, int>{key, value});
      map_[key] = list_.begin();
    } else {
      list_.erase(map_[key]);
      map_.erase(key);

      list_.push_front(pair<int, int>{key, value});
      map_[key] = list_.begin();
    }
  }

 private:
  unordered_map<int, list<pair<int, int>>::iterator> map_{};
  list<pair<int, int>> list_{};
  int cap_ = 0;
};
