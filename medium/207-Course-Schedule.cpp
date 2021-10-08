/* There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i] =
 * [ai, bi] indicates that you must take course bi first if you want to take
 * course ai. For example, the pair [0, 1], indicates that to take course 0 you
 * have to first take course 1. Return true if you can finish all courses.
 * Otherwise, return false.
 */

#include <vector>

using std::vector;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> v(numCourses, vector<int>{});  // course-dependences
    vector<int> flags(numCourses, true);

    int counts = 0;  // can't size
    for (auto& t : prerequisites) {
      if (v[t[0]].empty()) {
        counts++;
      }
      flags[t[0]] = false;      // can't
      v[t[0]].push_back(t[1]);  // dependence
    }

    int temp;
    int size;
    bool changed = true;
    while (changed && counts != 0) {
      changed = false;
      for (int i = 0; i < v.size(); i++) {
        if (flags[i] || v[i].empty()) {
          continue;
        }

        size = v[i].size();
        temp = 0;
        for (auto x : v[i]) {
          if (flags[x]) {
            temp++;
          } else {
            break;
          }
        }
        if (size == temp) {  // all dependences can
          flags[i] = true;
          changed = true;
          counts--;
        }
      }
    }
    return counts == 0;
  }
};
