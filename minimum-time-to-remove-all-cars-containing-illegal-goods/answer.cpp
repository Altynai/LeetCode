class Solution {
public:
  int minimumTime(string s) {
    int n = s.size();
    int max_val = 0;
    int sum = 0, ans = n;
    for (int i = 0; i < n; i++) {
      sum += (s[i] == '1' ? 1 : -1);
      ans = min(ans, sum - max_val);
      max_val = max(sum, max_val);
    }
    return min(n, n + ans);
  }
};
