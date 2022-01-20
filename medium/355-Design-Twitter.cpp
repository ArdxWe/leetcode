/*
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user, and is able to see the 10 most recent tweets in
 * the user's news feed. Implement the Twitter class: Twitter() Initializes your
 * twitter object. void postTweet(int userId, int tweetId) Composes a new tweet
 * with ID tweetId by the user userId. Each call to this function will be made
 * with a unique tweetId. List<Integer> getNewsFeed(int userId) Retrieves the 10
 * most recent tweet IDs in the user's news feed. Each item in the news feed
 * must be posted by users who the user followed or by the user themself. Tweets
 * must be ordered from most recent to least recent. void follow(int followerId,
 * int followeeId) The user with ID followerId started following the user with
 * ID followeeId. void unfollow(int followerId, int followeeId) The user with ID
 * followerId started unfollowing the user with ID followeeId.
 */

#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::pair;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Twitter {
 public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    map_[userId].second.push_back({times_++, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> v;
    for (auto item : map_[userId].first) {
      v.push_back(item);
    }
    v.push_back(userId);

    vector<int> cursor;
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
      cursor.push_back(map_[v[i]].second.size() - 1);
    }

    vector<int> res;

    vector<pair<uint64_t, int>> temp;
    for (int i = 0; i < 10; i++) {
      int valid = 0;
      for (int i = 0; i < cursor.size(); i++) {
        if (cursor[i] < 0)
          temp.push_back({0, -1});
        else {
          valid++;
          temp.push_back(map_[v[i]].second[cursor[i]]);
        }
      }
      if (valid == 0) break;

      int max_position =
          std::max_element(temp.begin(), temp.end()) - temp.begin();
      cursor[max_position]--;

      res.push_back(temp[max_position].second);
      temp.clear();
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    map_[followerId].first.insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    map_[followerId].first.erase(followeeId);
  }

 private:
  unordered_map<int, pair<unordered_set<int>, vector<pair<uint64_t, int>>>>
      map_{};
  uint64_t times_ = 1;
};
