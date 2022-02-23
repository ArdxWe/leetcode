/*
 * There are n dominoes in a line, and we place each domino vertically upright.
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left. Similarly, the dominoes falling to the right
 * push their adjacent dominoes standing on the right. When a vertical domino
 * has dominoes falling on it from both sides, it stays still due to the balance
 * of the forces. For the purposes of this question, we will consider that a
 * falling domino expends no additional force to a falling or already fallen
 * domino. You are given a string dominoes representing the initial state
 * where:dominoes[i] = 'L', if the ith domino has been pushed to the left,
 * dominoes[i] = 'R', if the ith domino has been pushed to the right, and
 * dominoes[i] = '.', if the ith domino has not been pushed. Return a string
 * representing the final state.
 */

#include <cassert>
#include <string>
#include <unordered_map>

namespace {
using std::string;
using std::unordered_map;
}  // namespace

class Solution {
 private:
  enum class Flag {
    left,
    right,
  };

 public:
  string pushDominoes(const string& dominoes) {
    string res = dominoes;

    // will affect others
    unordered_map<int, Flag> map;
    for (int i = 0; i < static_cast<int>(dominoes.size()); i++) {
      if (dominoes[i] == 'L') {
        map[i] = Flag::left;
      } else if (dominoes[i] == 'R') {
        map[i] = Flag::right;
      } else {
        assert(dominoes[i] == '.');
      }
    }

    while (true) {
      unordered_map<int, Flag> new_map;

      for (const auto& pair : map) {
        if (pair.second == Flag::left) {
          // no left
          if (pair.first - 1 < 0) {
            continue;
          }

          // left is affecting others
          if (map.find(pair.first - 1) != map.end()) {
            continue;
          } else {
            if (res[pair.first - 1] != '.') {
              continue;
            }

            assert(res[pair.first - 1] == '.');
            if (pair.first - 2 >= 0 && map.find(pair.first - 2) != map.end() &&
                map[pair.first - 2] == Flag::right) {
            } else {
              res[pair.first - 1] = 'L';
              new_map[pair.first - 1] = Flag::left;
            }
          }
        } else {
          // no right
          if (pair.first + 1 >= res.size()) {
            continue;
          }

          // right is affecting others
          if (map.find(pair.first + 1) != map.end()) {
            continue;
          } else {
            if (res[pair.first + 1] != '.') {
              continue;
            }
            assert(res[pair.first + 1] == '.');

            if (pair.first + 2 < res.size() &&
                map.find(pair.first + 2) != map.end() &&
                map[pair.first + 2] == Flag::left) {
            } else {
              res[pair.first + 1] = 'R';
              new_map[pair.first + 1] = Flag::right;
            }
          }
        }
      }
      if (new_map.empty()) {
        break;
      }

      map = new_map;
    }
    return res;
  }
};

int main() {
  Solution s;
  s.pushDominoes(".L.R...LR..L..");
  return 0;
}
