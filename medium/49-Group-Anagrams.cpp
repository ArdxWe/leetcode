/*
 * Given an array of strings strs, group the anagrams together.
 * You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 */

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    auto build_str = [](const string& str) {
      stringstream res;
      array<int, 26> characters = {0};
      for (char c : str) {
        characters[c - 'a']++;
      }
      for (int i = 0; i < characters.size(); i++) {
        if (characters[i] > 0) {
          res << static_cast<char>('a' + i);
          res << characters[i];
        }
      }
      return res.str();
    };

    for (int i = 0; i < strs.size(); i++) {
      map_[build_str(strs[i])].push_back(i);
    }

    vector<vector<string>> s;
    for (auto& pair : map_) {
      vector<string> now;
      for (int i : pair.second) {
        now.push_back(strs[i]);
      }
      s.push_back(std::move(now));
    }
    return s;
  }

 private:
  unordered_map<string, vector<int>> map_{};
};

/*
int main() {
  Solution s;
  vector<string> x = {"ddddddddddg", "dgggggggggg"};
  auto t = s.groupAnagrams(x);
  for (auto& i : t) {
    for (auto& y : i) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}
*/
