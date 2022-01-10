/*
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a
 * tiny URL. There is no restriction on how your encode/decode algorithm should
 * work. You just need to ensure that a URL can be encoded to a tiny URL and the
 * tiny URL can be decoded to the original URL. Implement the Solution class:
 * Solution() Initializes the object of the system.
 * String encode(String longUrl) Returns a tiny URL for the given longUrl.
 * String decode(String shortUrl) Returns the original long URL for the given
 * shortUrl. It is guaranteed that the given shortUrl was encoded by the same
 * object.
 */

#include <string>
#include <unordered_map>

namespace {
using std::string;
using std::unordered_map;
}  // namespace

class Solution {
 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (map_string_as_key_.find(longUrl) != map_string_as_key_.end()) {
      return to_string(map_string_as_key_[longUrl]);
    } else {
      map_string_as_key_[longUrl] = count_;

      map_[count_] = longUrl;

      return to_string(count_++);
    }
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) { return map_[atoi(shortUrl.data())]; }

 private:
  int count_ = 0;
  unordered_map<int, string> map_{};

  unordered_map<string, int> map_string_as_key_{};
};
