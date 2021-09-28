/* The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
 * 'C', 'G', and 'T'. For example, "ACGAATTCCG" is a DNA sequence. When studying
 * DNA, it is useful to identify repeated sequences within the DNA. Given a
 * string s that represents a DNA sequence, return all the 10-letter-long
 * sequences (substrings) that occur more than once in a DNA molecule. You may
 * return the answer in any order.
 */

#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> set;
    unordered_set<string> res_m;

    vector<string> res;
    for (int i = 0; i <= static_cast<int>(s.size() - 10); i++) {
      string a = string(s.data() + i, 10);

      if (res_m.find(a) != res_m.end()) {
        continue;
      }

      if (set.find(a) == set.end()) {
        set.insert(std::move(a));
      } else {
        res_m.insert(a);
        res.push_back(std::move(a));
      }
    }
    return res;
  }
};
