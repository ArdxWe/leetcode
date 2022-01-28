/* Suppose you are given the following code:
 * class FooBar {
 *   public void foo() {
 *     for (int i = 0; i < n; i++) {
 *       print("foo");
 *     }
 *   }
 *   public void bar() {
 *     for (int i = 0; i < n; i++) {
 *       print("bar");
 *     }
 *   }
 * }
 * The same instance of FooBar will be passed to two different threads:
 * thread A will call foo(), while
 * thread B will call bar().
 * Modify the given program to output "foobar" n times.
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

class FooBar {
 private:
  int n = 0;

  mutex mutex_{};
  condition_variable cv_{};
  int turn = 0;

 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n + 1; i++) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] { return this->turn % 2 == 0; });
        if (turn == 2 * n) {
          turn++;
          cv_.notify_one();
          return;
        }
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        turn++;
      }
      cv_.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n + 1; i++) {
      {
        unique_lock<mutex> lk{mutex_};
        cv_.wait(lk, [&] { return this->turn % 2 == 1; });

        if (turn > 2 * n) {
          return;
        }

        // printBar() outputs "bar". Do not change or remove this line.
        printBar();

        turn++;
      }
      cv_.notify_one();
    }
  }
};
