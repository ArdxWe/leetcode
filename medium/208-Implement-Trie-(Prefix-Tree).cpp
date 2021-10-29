/* A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 * Implement the Trie class:

 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * inserted string word that has the prefix prefix, and false otherwise.
 */

#include <array>
#include <cassert>
#include <memory>
#include <string>
#include <vector>

namespace {
using std::array;
using std::pair;
using std::string;
using std::unique_ptr;

const int kLens = 26;

struct Node {
  bool key;
  array<Node*, kLens> next;

  Node() : key{false}, next{nullptr} {};
};

void deleteNode(Node* node) {
  if (node == nullptr) {
    return;
  }

  for (auto n : node->next) {
    deleteNode(n);
  }
  delete node;
}

}  // namespace

class Trie {
 public:
  Trie() : v_{new Node()} {}

  void insert(const string& word) {
    assert(word.size() > 0);

    Node* now = v_;
    for (const auto i : word) {
      if (now->next[i - 'a'] == nullptr) {
        now->next[i - 'a'] = new Node();
      }
      now = now->next[i - 'a'];
    }
    now->key = true;
  }

  bool search(const string& word) {
    Node* now = v_;

    for (const auto i : word) {
      if (now->next[i - 'a'] == nullptr) {
        return false;
      }
      now = now->next[i - 'a'];
    }

    return now->key;
  }

  bool startsWith(const string& prefix) {
    Node* now = v_;

    for (const auto i : prefix) {
      if (now->next[i - 'a'] == nullptr) {
        return false;
      }
      now = now->next[i - 'a'];
    }

    return true;
  }

  ~Trie() { deleteNode(v_); }

 private:
  Node* v_ = nullptr;
};
