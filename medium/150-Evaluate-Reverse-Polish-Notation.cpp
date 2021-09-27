/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, and /. Each operand may be an integer or another
 * expression. Note that division between two integers should truncate toward
 * zero. It is guaranteed that the given RPN expression is always valid. That
 * means the expression would always evaluate to a result, and there will not be
 * any division by zero operation.
 */

#include <cassert>
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
  enum class F {
    ADD = 0,
    SUB,
    MUL,
    DIV,
  };

  void func(vector<int>& stack, enum F f) {
    assert(stack.size() >= 2);
    int a = stack[stack.size() - 1];
    int b = stack[stack.size() - 2];
    stack.pop_back();
    stack.pop_back();
    int c;
    switch (f) {
      case F::ADD:
        c = b + a;
        break;
      case F::SUB:
        c = b - a;
        break;
      case F::MUL:
        c = b * a;
        break;
      case F::DIV:
        c = b / a;
        break;
      default:
        assert(-1);
    }
    stack.push_back(c);
  }

  int evalRPN(vector<string>& tokens) {
    vector<int> stack;

    for (auto& s : tokens) {
      if (s == "(" || s == ")") {
        continue;
      }

      if (s == "+") {
        func(stack, F::ADD);
      } else if (s == "-") {
        func(stack, F::SUB);
      } else if (s == "*") {
        func(stack, F::MUL);
      } else if (s == "/") {
        func(stack, F::DIV);
      } else {
        int num = stoi(s);
        stack.push_back(num);
      }
    }
    assert(stack.size() == 1);
    return stack[0];
  }
};

int main() {
  vector<string> v = {"10", "6", "9",  "3", "+", "-11", "*",
                      "/",  "*", "17", "+", "5", "+"};
  Solution s;
  cout << s.evalRPN(v) << endl;
  return 0;
}
