/* There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i] =
 * [ai, bi] indicates that you must take course bi first if you want to take
 * course ai. For example, the pair [0, 1], indicates that to take course 0 you
 * have to first take course 1. Return the ordering of courses you should take
 * to finish all courses. If there are many valid answers, return any of them.
 * If it is impossible to finish all courses, return an empty array.
 */

#include <unordered_set>
#include <vector>

namespace {
using std::move;
using std::unordered_set;
using std::vector;
}  // namespace

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> v(numCourses, vector<int>{});

    vector<int> res;

    unordered_set<int> set;

    for (int i = 0; i < prerequisites.size(); i++) {
      set.insert(prerequisites[i][0]);
      v[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    unordered_set<int> new_set;
    for (int i = 0; i < numCourses; i++) {
      if (set.find(i) == set.end()) {
        new_set.insert(i);
        res.push_back(i);
      }
    }

    unordered_set<int> cans = move(new_set);
    bool quit = true;

    auto all_in = [](unordered_set<int>& cans, vector<int>& v) -> bool {
      for (auto t : v) {
        if (cans.find(t) == cans.end()) {
          return false;
        }
      }

      return true;
    };

    while (quit) {
      quit = false;
      for (int i = 0; i < numCourses; i++) {
        if (cans.find(i) == cans.end() && all_in(cans, v[i])) {
          cans.insert(i);
          res.push_back(i);
          quit = true;
          break;
        }
      }
    }

    if (cans.size() == numCourses) {
      return res;
    } else {
      return vector<int>{};
    }
  }
};
