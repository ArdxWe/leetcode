/*
 * A valid encoding of an array of words is any reference string s and array of
 * indices. indices such that: words.length == indices.length The reference
 * string s ends with the '#' character. For each index indices[i], the
 * substring of s starting from indices[i] and up to (but not including) the
 * next '#' character is equal to words[i]. Given an array of words, return the
 * length of the shortest reference string s possible of any valid encoding of
 * words.
 */

#include <array>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace {
using std::array;
using std::pair;
using std::string;
using std::unique_ptr;
using std::vector;
}  // namespace

static const int kSize = 26;

enum class Type : int {
  New,
  Longer,
  In,
  Created,
  None,
};

struct Node {
  array<unique_ptr<Node>, kSize> array_{};
  int valid_size_ = 0;

  pair<Type, int> insert(const string& s);
};

pair<Type, int> Node::insert(const string& s) {
  auto cur = this;

  Type type = Type::None;
  bool created = false;

  int prefix = 0;

  for (int i = static_cast<int>(s.size() - 1); i >= 0; i--) {
    if (cur->array_[s[i] - 'a']) {
    } else {
      if (!created && cur->valid_size_ == 0 && type != Type::Longer) {
        type = Type::Longer;
        prefix = static_cast<int>(s.size() - 1) - i;
      }
      if (!created) {
        created = true;
      }
      cur->array_[s[i] - 'a'] = unique_ptr<Node>(new Node());
      cur->valid_size_++;
    }

    cur = cur->array_[s[i] - 'a'].get();
  }

  if (type == Type::Longer) {
    if (prefix == 0) {
      return pair{Type::New, s.size()};
    }
    return pair{Type::Longer, s.size() - prefix};
  } else {
    if (created) {
      return pair{Type::Created, s.size()};
    }

    return pair{Type::In, 0};
  }
}

class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    int counts = 0;
    int res = 0;
    for (const auto& s : words) {
      auto value = node_.insert(s);

      if (value.first == Type::Longer) {
        res += value.second;
      } else if (value.first == Type::Created || value.first == Type::New) {
        res += value.second;
        counts++;
      } else if (value.first == Type::In) {
        continue;
      }
    }
    return res + counts;
  }

 private:
  Node node_{};
};
