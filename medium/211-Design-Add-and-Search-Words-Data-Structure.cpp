/* Design a data structure that supports adding new words and finding if a
 * string matches any previously added string. Implement the WordDictionary
 * class: WordDictionary() Initializes the object. void addWord(word) Adds word
 * to the data structure, it can be matched later. bool search(word) Returns
 * true if there is any string in the data structure that matches word or false
 * otherwise. word may contain dots '.' where dots can be matched with any
 * letter.
 */

#include <array>
#include <cassert>
#include <string>
#include <vector>

namespace {
using std::array;
using std::string;
using std::vector;

const int kLens = 26;

struct Node {
  bool word_exist;
  array<Node*, kLens> next;

  Node() : word_exist{false}, next{nullptr} {};
};

void deleteNode(Node* node) {
  if (node == nullptr) {
    return;
  }

  // delete child node
  for (auto n : node->next) {
    deleteNode(n);
  }
  // delete now node
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
    now->word_exist = true;
  }

  bool search(const string& word) {
    Node* now = v_;

    for (int i = 0; i < word.size(); i++) {
      if (word[i] == '.') {
        vector<Node*> all;
        for (int i = 0; i < kLens; i++) {
          if (now->next[i] != nullptr) {
            all.push_back(now->next[i]);
          }
        }
        auto t = my_find(all, string(word.data() + i + 1, word.size() - i - 1));
        for (auto i : t) {
          if (i->word_exist) {
            return true;
          }
        }
        return false;
      }

      if (now->next[word[i] - 'a'] == nullptr) {
        return false;
      }
      now = now->next[word[i] - 'a'];
    }

    return now->word_exist;
  }

  vector<Node*> my_find(vector<Node*>& v, const string& s) {
    if (s.empty()) {
      return v;
    }
    vector<Node*> all;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '.') {
        for (const auto x : v) {
          for (int i = 0; i < kLens; i++) {
            if (x->next[i] != nullptr) {
              all.push_back(x->next[i]);
            }
          }
        }
      } else {
        for (const auto x : v) {
          if (x->next[s[i] - 'a'] != nullptr) {
            all.push_back(x->next[s[i] - 'a']);
          }
        }
      }

      return my_find(all, string(s.data() + i + 1, s.size() - i - 1));
    }
    return vector<Node*>{};
  }

  ~Trie() { deleteNode(v_); }

 private:
  Node* v_ = nullptr;
};

class WordDictionary {
 public:
  WordDictionary() {}

  void addWord(const string& word) { t_.insert(word); }

  bool search(const string& word) { return t_.search(word); }

 private:
  Trie t_{};
};
