#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;

    if (digits.empty()) {
      return result;
    }

    buildDict();

    for (auto c : digits) {
      if (result.empty()) {
        result = dict_[c];
        continue;
      }
      vector<string> temp;
      for (const auto& s : dict_[c]) {
        for (const auto& current : result) {
          temp.push_back(current + s);
        }
      }
      result = temp;
    }
    return result;
  }

  void buildDict() {
    dict_['2'] = {"a", "b", "c"};
    dict_['3'] = {"d", "e", "f"};
    dict_['4'] = {"g", "h", "i"};
    dict_['5'] = {"j", "k", "l"};
    dict_['6'] = {"m", "n", "o"};
    dict_['7'] = {"p", "q", "r", "s"};
    dict_['8'] = {"t", "u", "v"};
    dict_['9'] = {"w", "x", "y", "z"};
  }

 private:
  unordered_map<char, vector<string>> dict_;
};
