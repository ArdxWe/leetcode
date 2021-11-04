/* Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of
 * s1 and s2. An interleaving of two strings s and t is a configuration where
 * they are divided into non-empty substrings such that:
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
 * t3 + s3 + ... Note: a + b is the concatenation of strings a and b.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::unordered_map;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    a_ = s1.size();
    b_ = s2.size();
    c_ = s3.size();
    if (a_ + b_ != c_) {
      return false;
    }

    return f(s1, 0, s2, 0, s3, 0);
  }

  bool f(string& s1, int index1, string& s2, int index2, string& s3,
         int index3) {
    stringstream stream;
    stream << index1 << "+" << index2 << "+" << index3;
    if (cache_.find(stream.str()) != cache_.end()) {
      return cache_[stream.str()];
    }

    if (index3 == c_) {
      cache_[stream.str()] = true;
      return true;
    }

    bool res = false;
    if (index1 < a_ && s3[index3] == s1[index1]) {
      res = res || f(s1, index1 + 1, s2, index2, s3, index3 + 1);
    }
    if (index2 < b_ && s3[index3] == s2[index2]) {
      res = res || f(s1, index1, s2, index2 + 1, s3, index3 + 1);
    }

    cache_[stream.str()] = res;
    return res;
  }

 private:
  int a_ = 0;
  int b_ = 0;
  int c_ = 0;

  unordered_map<string, bool> cache_{};
};

/*
int main() {
  Solution s;
  cout << s.isInterleave(string{"aabcc"}, string{"dbbca"}, string{"aadbbbaccc"})
       << endl;
  return 0;
}
*/
