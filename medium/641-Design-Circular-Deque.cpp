/*
 * Design your implementation of the circular double-ended queue (deque).
 * Implement the MyCircularDeque class:
 * MyCircularDeque(int k) Initializes the deque with a maximum size of k.
 * boolean insertFront() Adds an item at the front of Deque. Returns true if the
 * operation is successful, or false otherwise. boolean insertLast() Adds an
 * item at the rear of Deque. Returns true if the operation is successful, or
 * false otherwise. boolean deleteFront() Deletes an item from the front of
 * Deque. Returns true if the operation is successful, or false otherwise.
 * boolean deleteLast() Deletes an item from the rear of Deque. Returns true if
 * the operation is successful, or false otherwise. int getFront() Returns the
 * front item from the Deque. Returns -1 if the deque is empty. int getRear()
 * Returns the last item from Deque. Returns -1 if the deque is empty. boolean
 * isEmpty() Returns true if the deque is empty, or false otherwise. boolean
 * isFull() Returns true if the deque is full, or false otherwise.
 */

#include <list>

namespace {
using std::list;
}  // namespace

class MyCircularDeque {
 public:
  explicit MyCircularDeque(int k) { max_size_ = k; }

  bool insertFront(int value) {
    if (list_.size() == max_size_) {
      return false;
    }
    list_.push_front(value);
    return true;
  }

  bool insertLast(int value) {
    if (list_.size() == max_size_) {
      return false;
    }
    list_.push_back(value);
    return true;
  }

  bool deleteFront() {
    if (list_.empty()) {
      return false;
    }
    list_.pop_front();
    return true;
  }

  bool deleteLast() {
    if (list_.empty()) {
      return false;
    }
    list_.pop_back();
    return true;
  }

  int getFront() {
    if (list_.empty()) {
      return -1;
    }
    return list_.front();
  }

  int getRear() {
    if (list_.empty()) {
      return -1;
    }
    return list_.back();
  }

  bool isEmpty() { return list_.empty(); }

  bool isFull() { return list_.size() == max_size_; }

 private:
  list<int> list_{};
  int max_size_ = 0;
};
