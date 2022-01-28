/*
 * You have a function printNumber that can be called with an integer parameter
 * and prints it to the console. For example, calling printNumber(7) prints 7 to
 * the console. You are given an instance of the class ZeroEvenOdd that has
 * three functions: zero, even, and odd. The same instance of ZeroEvenOdd will
 * be passed to three different threads: Thread A: calls zero() that should only
 * output 0's. Thread B: calls even() that should only output even numbers.
 * Thread C: calls odd() that should only output odd numbers.
 * Modify the given class to output the series "010203040506..." where the
 * length of the series must be 2n. Implement the ZeroEvenOdd class:
 * ZeroEvenOdd(int n) Initializes the object with the number n that represents
 * the numbers that should be printed. void zero(printNumber) Calls printNumber
 * to output one zero. void even(printNumber) Calls printNumber to output one
 * even number. void odd(printNumber) Calls printNumber to output one odd
 * number.
 */

#include <condition_variable>
#include <functional>
#include <mutex>

namespace {
using std::condition_variable;
using std::function;
using std::mutex;
using std::unique_lock;
}  // namespace

class ZeroEvenOdd {
 private:
  int n = 0;
  mutex mutex_{};
  condition_variable cv_{};
  int turn = 0;
  bool quit = false;

 public:
  ZeroEvenOdd(int n) { this->n = n; }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] { return turn % 2 == 0; });

        if (turn == 2 * n) {
          quit = true;
          lk.unlock();
          cv_.notify_all();
          return;
        }

        printNumber(0);
        turn++;
      }
      cv_.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] { return turn % 4 == 3 || quit; });

        if (quit) {
          return;
        }

        printNumber((turn + 1) / 2);
        turn++;
      }
      cv_.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] { return turn % 4 == 1 || quit; });

        if (quit) {
          return;
        }

        printNumber((turn + 1) / 2);
        turn++;
      }
      cv_.notify_all();
    }
  }
};
