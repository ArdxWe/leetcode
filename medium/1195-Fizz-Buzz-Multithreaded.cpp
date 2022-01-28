/* You have the four functions:
 * printFizz that prints the word "Fizz" to the console,
 * printBuzz that prints the word "Buzz" to the console,
 * printFizzBuzz that prints the word "FizzBuzz" to the console, and
 * printNumber that prints a given integer to the console.
 * You are given an instance of the class FizzBuzz that has four functions:
 * fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed
 * to four different threads: Thread A: calls fizz() that should output the word
 * "Fizz". Thread B: calls buzz() that should output the word "Buzz". Thread C:
 * calls fizzbuzz() that should output the word "FizzBuzz". Thread D: calls
 * number() that should only output the integers. Modify the given class to
 * output the series [1, 2, "Fizz", 4, "Buzz", ...] where the ith token
 * (1-indexed) of the series is: "FizzBuzz" if i is divisible by 3 and 5, "Fizz"
 * if i is divisible by 3 and not 5, "Buzz" if i is divisible by 5 and not 3, or
 * i if i is not divisible by 3 or 5.
 * Implement the FizzBuzz class:
 * FizzBuzz(int n) Initializes the object with the number n that represents the
 * length of the sequence that should be printed. void fizz(printFizz) Calls
 * printFizz to output "Fizz". void buzz(printBuzz) Calls printBuzz to output
 * "Buzz". void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output
 * "FizzBuzz". void number(printNumber) Calls printnumber to output the numbers.
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

class FizzBuzz {
 private:
  int n_ = 0;
  int turn_ = 1;
  mutex mutex_{};
  condition_variable cv_{};
  bool quit_ = false;

 public:
  explicit FizzBuzz(int n) { this->n_ = n; }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] {
          return (this->turn_ % 3 == 0 && this->turn_ % 5 != 0) || this->quit_;
        });
        if (quit_) {
          return;
        }
        printFizz();
        if (turn_ == n_) {
          quit_ = true;
          lk.unlock();
          cv_.notify_all();
          return;
        }
        turn_++;
        cv_.notify_all();
      }
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] {
          return (this->turn_ % 3 != 0 && this->turn_ % 5 == 0) || this->quit_;
        });
        if (quit_) {
          return;
        }
        printBuzz();
        if (turn_ == n_) {
          quit_ = true;
          lk.unlock();
          cv_.notify_all();
          return;
        }
        turn_++;
        cv_.notify_all();
      }
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] {
          return (this->turn_ % 3 == 0 && this->turn_ % 5 == 0) || this->quit_;
        });
        if (quit_) {
          return;
        }
        printFizzBuzz();
        if (turn_ == n_) {
          quit_ = true;
          lk.unlock();
          cv_.notify_all();
          return;
        }
        turn_++;
        cv_.notify_all();
      }
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    while (true) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] {
          return (this->turn_ % 3 != 0 && this->turn_ % 5 != 0) || this->quit_;
        });
        if (quit_) {
          return;
        }
        printNumber(turn_);
        if (turn_ == n_) {
          quit_ = true;
          lk.unlock();
          cv_.notify_all();
          return;
        }
        turn_++;
        cv_.notify_all();
      }
    }
  }
};
