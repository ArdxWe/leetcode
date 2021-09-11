/* Given a string path, which is an absolute path (starting with a slash '/') to
 * a file or directory in a Unix-style file system, convert it to the simplified
 * canonical path. In a Unix-style file system, a period '.' refers to the
 * current directory, a double period '..' refers to the directory up a level,
 * and any multiple consecutive slashes (i.e. '//') are treated as a single
 * slash '/'. For this problem, any other format of periods such as '...' are
 * treated as file/directory names. The canonical path should have the following
 * format: The path starts with a single slash '/'. Any two directories are
 * separated by a single slash '/'. The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory to
 * the target file or directory (i.e., no period '.' or double period '..')
 * Return the simplified canonical path.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

class Solution {
 public:
  string simplifyPath(string path) {
    stringstream stream{path};
    string s;
    vector<string> x;

    while (getline(stream, s, '/')) {
      if (!s.empty()) {
        if (s == "..") {
          if (x.empty()) {
            x.clear();
          } else {
            x.pop_back();
          }
        } else if (s != ".") {
          x.push_back(s);
        }
      }
    }
    stringstream res;
    for (auto& s : x) {
      res << "/" << s;
    }
    if (x.empty()) return "/";
    return res.str();
  }
};

/*
int main() {
  Solution s;
  cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
  return 0;
}
*/
