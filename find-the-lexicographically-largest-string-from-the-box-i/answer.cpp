class Solution {
public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1)
      return word;

    int n = word.size();
    int max_length = n - (numFriends - 1);
    char ch = *max_element(word.begin(), word.end());

    // pos, current length
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      if (word[i] == ch) {
        v.push_back({i, 1});
      }
    }

    for (int t = 2; t <= max_length; t++) {
      vector<pair<int, int>> v2;

      int nxt = -1;
      for (auto [i, len] : v) {
        if (i + 1 < n and word[i + 1] - 'a' > nxt)
          nxt = word[i + 1] - 'a';
      }
      for (auto [i, len] : v) {
        if (i + 1 < n and word[i + 1] - 'a' == nxt)
          v2.push_back({i + 1, len + 1});
      }
      if (v2.empty())
        break;
      swap(v, v2);
    }

    assert(!v.empty());
    auto [pos, len] = v[0];
    return word.substr(pos - len + 1, len);
  }
};
