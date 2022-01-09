#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int wordCount(vector<string> &startWords, vector<string> &targetWords) {
    const int N = 26;
    unordered_set<int> seen;
    for (string s : startWords) {
      int mask = 0;
      for (char ch : s)
        mask |= 1 << (ch - 'a');
      seen.insert(mask);
    }

    int ans = 0;
    for (string s : targetWords) {
      int mask = 0;
      for (char ch : s)
        mask |= 1 << (ch - 'a');

      bool found = 0;
      for (int i = 0; !found and i < N; i++) {
        if (bit(mask, i) and seen.count(mask ^ (1 << i)))
          found = 1;
      }
      if (found)
        ans++;
    }
    return ans;
  }
};
