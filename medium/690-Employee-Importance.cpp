/*
 * You have a data structure of employee information, including the employee's
 * unique ID, importance value, and direct subordinates' IDs. You are given an
 * array of employees. employees where: employees[i].id is the ID of the ith
 * employee. employees[i].importance is the importance value of the ith
 * employee. employees[i].subordinates is a list of the IDs of the direct
 * subordinates of the ith employee. Given an integer id that represents an
 * employee's ID, return the total importance value of this employee and all
 * their direct and indirect subordinates.
 */

#include <cassert>
#include <unordered_map>
#include <vector>

namespace {
using std::unordered_map;
using std::vector;
}  // namespace

// Definition for Employee.
class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> map;
    for (const auto e : employees) {
      assert(map.find(e->id) == map.end());
      map[e->id] = e;
    }

    return get_all(map, id);
  }

  int get_all(unordered_map<int, Employee*> map, int id) {
    assert(map.find(id) != map.end());

    if (cache_.find(id) != cache_.end()) {
      return cache_[id];
    }

    int res = map[id]->importance;
    for (const auto e : map[id]->subordinates) {
      res += get_all(map, e);
    }

    cache_[id] = res;
    return res;
  }

 private:
  unordered_map<int, int> cache_{};
};
