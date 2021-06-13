class Solution {
public:
  bool makeEqual(vector<string> &words) {
    vector<int> cnt(26, 0);
    int n = words.size();
    for (string w : words) {
      for (char c : w) {
        cnt[c - 'a']++;
        cnt[c - 'a'] %= n;
      }
    }
    return accumulate(cnt.begin(), cnt.end(), 0) == 0;
  }
};
