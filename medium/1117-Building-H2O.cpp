/* There are two kinds of threads: oxygen and hydrogen. Your goal is to group
 * these threads to form water molecules. There is a barrier where each thread
 * has to wait until a complete molecule can be formed. Hydrogen and oxygen
 * threads will be given releaseHydrogen and releaseOxygen methods respectively,
 * which will allow them to pass the barrier. These threads should pass the
 * barrier in groups of three, and they must immediately bond with each other to
 * form a water molecule. You must guarantee that all the threads from one
 * molecule bond before any other threads from the next molecule do. In other
 * words: If an oxygen thread arrives at the barrier when no hydrogen threads
 * are present, it must wait for two hydrogen threads. If a hydrogen thread
 * arrives at the barrier when no other threads are present, it must wait for an
 * oxygen thread and another hydrogen thread. We do not have to worry about
 * matching the threads up explicitly; the threads do not necessarily know which
 * other threads they are paired up with. The key is that threads pass the
 * barriers in complete sets; thus, if we examine the sequence of threads that
 * bind and divide them into groups of three, each group should contain one
 * oxygen and two hydrogen threads. Write synchronization code for oxygen and
 * hydrogen molecules that enforces these constraints.
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

class H2O {
 public:
  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> lk{mutex_};
    cv_.wait(lk, [&] { return h_ <= 1; });
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    h_++;
    if (h_ == 2 && o_ == 1) {
      h_ = 0;
      o_ = 0;
    }
    cv_.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> lk{mutex_};
    cv_.wait(lk, [&] { return o_ == 0; });

    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    o_++;
    if (h_ == 2 && o_ == 1) {
      h_ = 0;
      o_ = 0;
    }
    cv_.notify_all();
  }

 private:
  mutex mutex_{};
  condition_variable cv_{};
  int h_ = 0;
  int o_ = 0;
};
