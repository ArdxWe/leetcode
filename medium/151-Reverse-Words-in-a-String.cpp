/* Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space. Return a string of the words in reverse
 * order concatenated by a single space. Note that s may contain leading or
 * trailing spaces or multiple spaces between two words. The returned string
 * should only have a single space separating the words. Do not include any
 * extra spaces.
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
  string reverseWords(string s) {
    stringstream stream{s};
    string temp;
    vector<string> v;
    while (stream >> temp) {
      v.push_back(std::move(temp));
    }

    stringstream x;
    for (int i = v.size() - 1; i >= 0; i--) {
      x << v[i];
      if (i != 0) {
        x << " ";
      }
    }
    return x.str();
  }
};

int main() {
  Solution s;
  cout << s.reverseWords("Alice does not even like bob") << endl;
  return 0;
}
