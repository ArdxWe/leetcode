/* Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format. If the fractional part is repeating,
 * enclose the repeating part in parentheses. If multiple answers are possible,
 * return any of them. It is guaranteed that the length of the answer string is
 * less than 104 for all the given inputs.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::unordered_map;

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    long n = numerator;
    long d = denominator;
    if (n == 0) {
      return "0";
    }
    unordered_map<string, long> map;
    stringstream stream;
    if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
      stream << "-";
    }
    if (n < 0) {
      n = -n;
    }
    if (d < 0) {
      d = -d;
    }
    stream << n / d;

    n = n % d;
    if (n == 0) {
      return stream.str();
    }

    stream << ".";

    stringstream s;
    long val;
    long end;
    string temp;
    long index = 0;
    while (n != 0) {
      val = n * 10 / d;
      end = n * 10 % d;
      temp = std::to_string(val) + "+" + std::to_string(end);

      if (map.find(temp) != map.end()) {
        stringstream x;
        x << string(s.str().data(), map[temp])
          << "(" +
                 string{s.str().data() + map[temp],
                        s.str().size() - 1 - map[temp] + 1} +
                 ")";
        stream << x.str();
        return stream.str();
      }

      s << val;
      map[temp] = index++;
      n = end;
    }
    stream << s.str();
    return stream.str();
  }
};

int main() {
  Solution s;
  cout << s.fractionToDecimal(4, 333) << endl;
  return 0;
}
