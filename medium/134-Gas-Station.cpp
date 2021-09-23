/* There are n gas stations along a circular route, where the amount of gas at
 * the ith station is gas[i]. You have a car with an unlimited gas tank and it
 * costs cost[i] of gas to travel from the ith station to its next (i + 1)th
 * station. You begin the journey with an empty tank at one of the gas stations.
 * Given two integer arrays gas and cost, return the starting gas station's
 * index if you can travel around the circuit once in the clockwise direction,
 * otherwise return -1. If there exists a solution, it is guaranteed to be
 * unique
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<bool> flags(gas.size(), false);

    for (int i = 0; i < gas.size(); i++) {
      if (flags[i]) {
        break;
      }
      flags[i] = true;
      if (gas[i] - cost[i] < 0) {
        continue;
      }

      int end = get(gas, cost, i);
      if (end == i) {
        return end;
      } else {
        i = end - 1;  // because of i++
      }
    }
    return -1;
  }

  int get(vector<int>& gas, vector<int>& cost, int start) {
    int now = 0;
    int index = start;
    int len = 0;
    while (now >= 0 && len < gas.size()) {
      len++;
      now += gas[index] - cost[index];
      if (now < 0) {
        return index;
      }

      index++;
      if (index == gas.size()) {
        index = 0;
      }
    }
    return index;
  }
};

int main() {
  Solution s;
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  cout << s.canCompleteCircuit(gas, cost) << endl;
  return 0;
}
