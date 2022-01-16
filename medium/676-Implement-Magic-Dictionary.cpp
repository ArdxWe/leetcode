/*
 * Design a data structure that is initialized with a list of different words.
 * Provided a string, you should determine if you can change exactly one
 * character in this string to match any word in the data structure. Implement
 * the MagicDictionary class: MagicDictionary() Initializes the object. void
 * buildDict(String[] dictionary) Sets the data structure with an array of
 * distinct strings dictionary. bool search(String searchWord) Returns true if
 * you can change exactly one character in searchWord to match any string in the
 * data structure, otherwise returns false.
 */

#include <cassert>
#include <string>
#include <vector>

namespace {
using std::string;
using std::vector;

bool compare(const string& a, const string& b) {
  assert(a.size() == b.size());

  int diff = 0;

  for (int i = 0; i < static_cast<int>(a.size()); i++) {
    if (a[i] != b[i]) {
      diff++;
      if (diff > 1) return false;
    }
  }

  return diff == 1;
}
}  // namespace

class MagicDictionary {
 public:
  MagicDictionary() {}

  void buildDict(const vector<string>& dictionary) {
    for (const auto& s : dictionary) {
      v_[s.size()].push_back(s);
    }
  }

  bool search(const string& searchWord) {
    for (const auto& s : v_[searchWord.size()]) {
      if (compare(s, searchWord)) {
        return true;
      }
    }

    return false;
  }

 private:
  vector<vector<string>> v_{101, vector<string>{}};
};
