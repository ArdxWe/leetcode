/* You are playing a game that contains multiple characters, and each of the
 * characters has two main properties: attack and defense. You are given a 2D
 * integer array properties where properties[i] = [attacki, defensei] represents
 * the properties of the ith character in the game. A character is said to be
 * weak if any other character has both attack and defense levels strictly
 * greater than this character's attack and defense levels. More formally, a
 * character i is said to be weak if there exists another character j where
 * attackj > attacki and defensej > defensei. Return the number of weak
 * characters.
 */

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    auto compare = [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] - b[1] < 0;
      }
      return a[0] - b[0] > 0;
    };

    sort(properties.begin(), properties.end(), compare);

    int max_d = 0;

    int res = 0;
    for (int i = 0; i < properties.size(); i++) {
      if (properties[i][1] < max_d) {
        res++;
      } else {
        max_d = properties[i][1];
      }
    }
    return res;
  }
};
