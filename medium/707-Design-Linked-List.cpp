/*
 * Design your implementation of the linked list. You can choose to use a singly
 * or doubly linked list. A node in a singly linked list should have two
 * attributes: val and next. val is the value of the current node, and next is a
 * pointer/reference to the next node. If you want to use the doubly linked
 * list, you will need one more attribute prev to indicate the previous node in
 * the linked list. Assume all nodes in the linked list are 0-indexed. Implement
 * the MyLinkedList class: MyLinkedList() Initializes the MyLinkedList object.
 * int get(int index) Get the value of the indexth node in the linked list. If
 * the index is invalid, return -1. void addAtHead(int val) Add a node of value
 * val before the first element of the linked list. After the insertion, the new
 * node will be the first node of the linked list. void addAtTail(int val)
 * Append a node of value val as the last element of the linked list. void
 * addAtIndex(int index, int val) Add a node of value val before the indexth
 * node in the linked list. If index equals the length of the linked list, the
 * node will be appended to the end of the linked list. If index is greater than
 * the length, the node will not be inserted. void deleteAtIndex(int index)
 * Delete the indexth node in the linked list, if the index is valid.
 */

#include <cassert>
#include <memory>
#include <utility>

namespace {
using std::move;
using std::unique_ptr;
}  // namespace

struct List {
  unique_ptr<List> next{};
  int val = 0;

  List() = default;

  List(int val, unique_ptr<List> next) : val(val), next(move(next)) {}
};

class MyLinkedList {
 public:
  MyLinkedList() = default;

  int get(int index) {
    List* ptr = get_pointer(index);

    if (ptr != nullptr) {
      return ptr->val;
    }

    return -1;
  }

  void addAtHead(int val) {
    if (size_ == 0) {
      assert(!list_);
    }

    // link
    unique_ptr<List> head{new List(val, move(list_))};

    list_ = move(head);
    size_++;
  }

  void addAtTail(int val) {
    if (size_ == 0) {
      assert(!list_);

      list_ = unique_ptr<List>(new List(val, nullptr));

      size_++;
      return;
    }

    List* tail = get_pointer(size_ - 1);

    assert(tail != nullptr);

    tail->next = unique_ptr<List>(new List(val, nullptr));

    size_++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0) {
      addAtHead(val);
    } else if (index > size_) {
      return;
    }

    if (index == 0) {
      unique_ptr<List> ptr(new List(val, move(list_)));

      list_ = move(ptr);
      size_++;
      return;
    }

    List* prev = get_pointer(index - 1);
    assert(prev != nullptr);

    auto ptr = unique_ptr<List>(new List(val, move(prev->next)));
    prev->next = move(ptr);

    size_++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size_) {
      return;
    }

    if (index == 0) {
      list_ = move(list_->next);
      size_--;
      return;
    }

    List* prev = get_pointer(index - 1);

    assert(prev != nullptr);

    if (prev->next) {
      prev->next = move(prev->next->next);
    }

    size_--;
  }

 private:
  List* get_pointer(int index) {
    if (index < 0 || index >= size_) {
      return nullptr;
    }

    // just read
    List* cur = list_.get();
    for (int i = 0; i < index; i++) {
      cur = cur->next.get();
    }

    return cur;
  }

  unique_ptr<List> list_{};
  int size_ = 0;
};
