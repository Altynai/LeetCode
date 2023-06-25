class Solution {
public:
  int maximumNumberOfStringPairs(vector<string> &words) {
    int n = words.size(), ans = 0;
    unordered_set<string> s;
    for (int i = 0; i < n; i++) {
      string t = words[i];
      reverse(t.begin(), t.end());
      if (s.count(t))
        ans++;
      s.insert(words[i]);
    }
    return ans;
  }
};
