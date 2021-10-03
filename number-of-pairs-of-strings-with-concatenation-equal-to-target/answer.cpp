class Solution {
public:
  int numOfPairs(vector<string> &s, string t) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        ans += (s[i] + s[j] == t);
      }
    }
    return ans;
  }
};
