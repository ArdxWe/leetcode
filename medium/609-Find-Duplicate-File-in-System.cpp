/*
 * Given a list paths of directory info, including the directory path, and all
 * the files with contents in this directory, return all the duplicate files in
 * the file system in terms of their paths. You may return the answer in any
 * order.
 * A group of duplicate files consists of at least two files that have the same
 * content.
 * A single directory info string in the input list has the following format:
 * "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ...
 * fn.txt(fn_content)"
 * It means there are n files (f1.txt, f2.txt ... fn.txt) with content
 * (f1_content, f2_content ... fn_content) respectively in the directory
 * "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the
 * directory is just the root directory.
 * The output is a list of groups of duplicate file paths. For each group, it
 * contains all the file paths of the files that have the same content. A file
 * path is a string that has the following format:
 * "directory_path/file_name.txt"
 */

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {
using std::istringstream;
using std::move;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;
}  // namespace

class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    vector<vector<string>> res;

    // content ---> file path
    unordered_map<string, vector<string>> map;

    for (const auto& s : paths) {
      // dir, <file_name, content>
      auto pair = parser(s);

      // push to map
      for (const auto& item : pair.second) {
        map[item.second].emplace_back(merge(pair.first, item.first));
      }
    }

    for (auto& item : map) {
      if (item.second.size() > 1) {
        res.emplace_back(move(item.second));
      }
    }

    return res;
  }

 private:
  pair<string, vector<pair<string, string>>> parser(const string& s) {
    pair<string, vector<pair<string, string>>> res;

    istringstream stream{s};
    stream >> res.first;

    string temp;
    while (stream >> temp) {
      auto pair = get_name_content(temp);
      res.second.emplace_back(move(pair));
    }

    return res;
  }

  pair<string, string> get_name_content(const string& s) {
    pair<string, string> res;
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
      if (s[i] == '(') {
        res.first = string(s.data(), i);
        res.second = string(s.data() + i + 1, s.size() - i - 2);
        return res;
      }
    }
    assert(false);
  }

  inline string merge(const string& dir, const string& file_name) {
    return dir + '/' + file_name;
  }
};
