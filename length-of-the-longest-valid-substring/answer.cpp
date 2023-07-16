class Solution {
public:
  int longestValidSubstring(string word, vector<string> &forbidden) {
    unordered_set<string> seen(forbidden.begin(), forbidden.end());
    int n = word.size();
    int ans = 0, r = n;
    for (int i = n - 1; i >= 0; i--) {
      string t = "";
      for (int j = i; j < min(n, i + 10); j++) {
        t.push_back(word[j]);
        if (seen.count(t)) {
          r = min(r, j);
          break;
        }
      }
      ans = max(ans, r - i);
    }
    return ans;
  }
};
