class Solution {
public:
  vector<int> divisibilityArray(string s, int m) {
    int n = s.size();
    vector<int> ans(n, 0);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum = sum * 10 + (s[i] - '0');
      sum %= m;
      if (sum == 0)
        ans[i] = 1;
    }
    return ans;
  }
};
